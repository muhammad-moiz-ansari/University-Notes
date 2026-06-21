package sports;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
 * Copyright (c) 2018 Philippe Fournier-Viger
 *
 * This pass predictor software (http://www.philippe-fournier-viger.com/foot2018/) is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * The software is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * the software. If not, see <http://www.gnu.org/licenses/>.
 */

public class MainPassPredictor {

	public static void main(String[] args) throws IOException {
		
		// PARAMETERS
		double radius = 682;
		
		boolean DEBUG = false;
		
		// For statistics, the number of senders without
		// position in the data file
		double numberOfSendersWithoutPosition = 0;
		
		// the number of passes to opposite team
		int numberOfInterceptions = 0;
		
		if(DEBUG){
		System.out.println("LOADING THE FILE ....");
		}
		
		String input = "D:\\workspace\\sports\\src\\passes.csv";
		
		// List of passes
		List<Pass> passes = new ArrayList<Pass>();
		
		// Read the file
		// We scan the database a first time to calculate the support of each item.
		BufferedReader myInput = null;
		String thisLine;
		// this variable will count the number of transactions
		int lineCount = 0;
		try {
			// prepare the object for reading the file
			myInput = new BufferedReader(new InputStreamReader( new FileInputStream(new File(input))));
			// for each line (transaction) until the end of file
			while ((thisLine = myInput.readLine()) != null) {
				if(lineCount == 0){
					// SKIP THE FIRST LINE
					lineCount++;
					continue;
				}
				
				if(DEBUG){
					System.out.println("=== THE LINE ====");
					System.out.println(thisLine);
				}
				
//				if("75200,77100,15,22,-1370.0,-370.0,-970.0,-2220.0,,-1910.0,-2410.0,-1770.0,-2710.0,310.0,-4070.0,,,-100.0,,3180.0,,-540.0,-480.0,,,1520.0,-2160.0,-2040.0,-2660.0,840.0,-1590.0,-70.0,900.0,1960.0,-220.0,-750.0,,-1230.0,250.0,2950.0,1590.0,740.0,190.0,,,3330.0,,50.0,,-300.0,-2590.0,,,1830.0,-1340.0,370.0,1630.0,-420.0,3110.0,1830.0".equals(thisLine)){
//					System.out.println();
//				}
				
				// Create a new pass object
				Pass pass = new Pass();
				passes.add(pass);
				 
				// Read the time
				String values[] = thisLine.split(","); 
				pass.timeStart = Long.parseLong(values[0]);
				pass.timeEnd = Long.parseLong(values[1]);
				
				// Read the sender and receiver ids
				pass.senderId = Integer.parseInt(values[2]);
				pass.receiverId = Integer.parseInt(values[3]);
				
				// These objects will be the sender and receivers
				pass.sender = null;
				pass.receiver = null;
				
				// Read the positions as X
				int k = 0;
				while(k < 28){
					// add the (k+1)-th player  if he is on the field
					if(values[4 + k].equals("") == false){
						Player player =  new Player();
						player.id = k+1;
						player.x = Double.parseDouble(values[4 + k]);
						player.y = Double.parseDouble(values[4 + 28 + k]);
//						System.out.println(player + " ");
						
						// If we found the sender we keep it.
						if(player.id == pass.senderId){
							pass.sender = player;
						}else{
							// otherwise we add the player as potential receivers
							pass.potentialReceivers.add(player);
						}
						
						// If we found the receiver we keep it.
						if(player.id == pass.receiverId){
							pass.receiver = player;
						}
					}
					
					k++;
//					if(k == 15){
//						System.out.println();
//					}
				}
				
				// x_1,x_2,x_3,x_4,x_5,x_6,x_7,x_8,x_9,x_10,x_11,x_12,x_13,x_14,x_15,x_16,x_17,x_18,x_19,x_20,x_21,x_22,x_23,x_24,x_25,x_26,x_27,x_28,
				// y_1,y_2,y_3,y_4,y_5,y_6,y_7,y_8,y_9,y_10,y_11,y_12,y_13,y_14,y_15,y_16,y_17,y_18,y_19,y_20,y_21,y_22,y_23,y_24,y_25,y_26,y_27,y_28
				
				if(DEBUG){
					System.out.println(" === THE PASS ====");
					System.out.println(pass);
	
					System.out.println(" === THE SENDER ====");
					System.out.println(pass.sender);
				}
				
				if(pass.sender == null){
					// NOTE THIS PROBLEM OF THE DATA
					numberOfSendersWithoutPosition++;
					continue;
				}else{
					// Compute the distance to potential receivers from sender
					for(Player potentialReceiver : pass.potentialReceivers){
						potentialReceiver.distanceToSender = 
								calculateDistance(potentialReceiver.x, potentialReceiver.y, pass.sender.x, pass.sender.y);
					}
				}

				if(DEBUG){
					System.out.println(" === THE RECEIVER ====");
					System.out.println(pass.receiver);
				}

				
				// Sort the players by distance to sender
				Collections.sort(pass.potentialReceivers,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.distanceToSender
										-
										o2.distanceToSender);
							}});
				
				// Print the potential receivers sorted by distance
				
//				System.out.println(" === THE POTENTIAL RECEIVERS SORTED BY DISTANCE ====");
//				
//				for(Player potentialReceiver : pass.potentialReceivers){
//					System.out.println(potentialReceiver);
//				}
				
				// Find the team of the sender
				boolean senderIsFromFirstTeam = pass.sender.id <= 14;
				
				//---------------------
				// Detect the pitch side
				double maxX = 99999;
				pass.leftMostPlayer = null;
				for(Player player : pass.potentialReceivers){
					if(player.x < maxX){
						maxX= player.x;
						pass.leftMostPlayer = player;
					}
				}
				
				if(pass.leftMostPlayer.id <= 14){
					pass.senderIsLeftSide = senderIsFromFirstTeam;
				}
				else{ // (pass.leftMostPlayer.id > 14)
					pass.senderIsLeftSide = !senderIsFromFirstTeam;
				}
				//---------------------
				
				// if an interception
				// update statistics
				if(pass.receiver != null){
					boolean receiverIsFromFirstTeam = pass.receiver.id <= 14;
					if(senderIsFromFirstTeam && !receiverIsFromFirstTeam){
						numberOfInterceptions++;
					}
					if(!senderIsFromFirstTeam && receiverIsFromFirstTeam){
						numberOfInterceptions++;
					}
				}
				
				
				// Separated the potential receivers by team
				for(Player potentialReceiver : pass.potentialReceivers){
					if(senderIsFromFirstTeam){
						if(potentialReceiver.id <=14){
							pass.potentialReceiversSameTeam.add(potentialReceiver);
						}else{
							pass.potentialReceiversOtherTeam.add(potentialReceiver);
						}
					}else{
						if(potentialReceiver.id <= 14){
							pass.potentialReceiversOtherTeam.add(potentialReceiver);
						}else{
							pass.potentialReceiversSameTeam.add(potentialReceiver);
						}
					}
				}
				
				// Find the shortest distance of each player to opposite team player
				for(Player potentialReceiver : pass.potentialReceiversSameTeam){
					potentialReceiver.distanceToClosestOppositeTeamPlayer = 999999999;
					for(Player oppositePlayer : pass.potentialReceiversOtherTeam){
						double distance = calculateDistance(potentialReceiver.x, potentialReceiver.y, oppositePlayer.x, oppositePlayer.y);
						if(distance < potentialReceiver.distanceToClosestOppositeTeamPlayer){
							potentialReceiver.distanceToClosestOppositeTeamPlayer = distance;
						}
						
						// update the count of number of opposite team member
						// within radius
						if(distance <= radius){
//							double distanceOppositeToSender = calculateDistance(oppositePlayer.x, oppositePlayer.y, 
//									pass.sender.x, pass.sender.y);
							
//							if(distanceOppositeToSender < potentialReceiver.distanceToSender){
								potentialReceiver.numberOppositeTeamPlayerWhithinRadius++;
//							}
						}
					}
				}
				
				// Find the shortest distance of each player to opposite team player
				for(Player potentialReceiver : pass.potentialReceiversOtherTeam){
					potentialReceiver.distanceToClosestOppositeTeamPlayer = 999999999;
					for(Player oppositePlayer : pass.potentialReceiversSameTeam){
						double distance = calculateDistance(potentialReceiver.x, potentialReceiver.y, oppositePlayer.x, oppositePlayer.y);
						if(distance < potentialReceiver.distanceToClosestOppositeTeamPlayer){
							potentialReceiver.distanceToClosestOppositeTeamPlayer = distance;
						}
						
						// update the count of number of opposite team member
						// whithin radius
						if(distance <= radius){
							potentialReceiver.numberOppositeTeamPlayerWhithinRadius++;
						}
					}
//					System.out.println(" ");
				}
				
				if(DEBUG){
					System.out.println(" === THE POTENTIAL RECEIVERS FROM SAME TEAM SORTED BY DISTANCE ====");
					// Find the potential receivers from opposite team
					for(Player potentialReceiver : pass.potentialReceiversSameTeam){
						System.out.println(potentialReceiver);
					}
					
					
					System.out.println(" === THE POTENTIAL RECEIVERS FROM OPPOSITE TEAM SORTED BY DISTANCE ====");
					// Find the potential receivers from opposite team
					for(Player potentialReceiver : pass.potentialReceiversOtherTeam){
						System.out.println(potentialReceiver);
					}
				}
				

				
				
//				promptEnterKey();
				
//				// for each item, we update its support
//				for(int i=0; i <items.length; i++){
//					// convert item to integer
//					
//					
//					System.out.println(item + " ");
//				}
			}
		} catch (Exception e) {
			// catches exception if error while reading the input file
			e.printStackTrace();
		}finally {
			if(myInput != null){
				myInput.close();
			}
	    }
		

		System.out.println("FINISHED LOADING THE FILE ....");
		

		// ==================================== //
		//====== STATS ABOUT DATA ========== //
		// ==================================== //
		System.out.println("=== STATS ABOUT DATA === ");
		System.out.println(" Total number of passes : " + passes.size());
		System.out.println(" Number of sender without position: " + numberOfSendersWithoutPosition);
		System.out.println(" Number of interceptions: " + numberOfInterceptions);

		System.out.println("=== DISTRIBUTION OF PASSES TEAM 1 ===== ");
		int arrayStatTeam1[][] = new int[15][15];
		int arrayStatTeam2[][] = new int[15][15];
		for(Pass pass : passes){
			if(pass.sender == null  || pass.receiver == null){
				continue;
			}
			boolean senderIsFromFirstTeam = pass.sender.id <= 14;
			boolean receiverIsFromFirstTeam = pass.receiver.id <= 14;
			if(senderIsFromFirstTeam && receiverIsFromFirstTeam){
				arrayStatTeam1[pass.sender.id][pass.receiver.id]++;
			}
			if(!senderIsFromFirstTeam && !receiverIsFromFirstTeam){
				arrayStatTeam2[pass.sender.id - 14][pass.receiver.id - 14]++;
			}
		}
		
		System.out.println("TEAM1");
		print2dArrayWithoutIndex1(arrayStatTeam1);
		System.out.println("TEAM2");
		print2dArrayWithoutIndex1(arrayStatTeam2);
		

		System.out.println();
		System.out.println("=== DISTRIBUTION OF PASSES RECEIVED BY PLAYER ===== ");
		int[] numberOfPassesByPlayer = new int[29];
		for(Pass pass : passes){
			if(pass.sender == null  || pass.receiver == null){
				continue;
			}
			numberOfPassesByPlayer[pass.receiverId]++;
		}
		System.out.println(Arrays.toString(numberOfPassesByPlayer));
		
		System.out.println();
		System.out.println("=== DISTRIBUTION OF PASSES SENT BY PLAYER ===== ");
		int[] numberOfPassesSentByPlayer = new int[29];
		for(Pass pass : passes){
			if(pass.sender == null  || pass.receiver == null){
				continue;
			}
			numberOfPassesSentByPlayer[pass.senderId]++;
		}
		System.out.println(Arrays.toString(numberOfPassesSentByPlayer));
		System.out.println("=======================================");
		
		// ==================================== //
		//====== BASELINE  (send to random team player on field) ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double totalPredictions  = 0d;
			double correctInTwoPredictions = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Random shuffle
				Collections.shuffle(pass.potentialReceiversSameTeam);
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
			}
			System.out.println("=== BASELINE (random team player on field) === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}
		
		// ==================================== //
		//====== PREDICTOR ONE ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;
				}

				// Sort the players by distance to sender
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});
				
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
				
			}
			System.out.println("=== PREDICTOR ONE (send to closest) === ");
			System.out.println(" Correct predictions " + correctPredictions);
			System.out.println(" Total predictions " + totalPredictions);
			System.out.println(" NUMBER OF SENDER WITHOUT POSITION " + numberOfSendersWithoutPosition);
			System.out.println(" Accuracy : " + (correctPredictions / totalPredictions * 100.0));
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}
		
		// ==================================== //
		//====== PREDICTOR TWO  (send to closest + penalty for opposite team player) ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;
					
					// HEURISTIC! ================
					if(player.distanceToClosestOppositeTeamPlayer < 700){
						player.score += 900;
					}
				}
				
				// Sort the players by distance to sender
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});

				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
				
			}
			System.out.println("=== PREDICTOR TWO (send to closest + penalty for opposite team player) === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}
		
		// ==================================== //
		//====== PREDICTOR THREE  (send to closest + penalty for opposite team player + angle penalty) ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;
					
					// HEURISTIC! ================
					if(player.distanceToClosestOppositeTeamPlayer < 700){
						player.score += 900;
					}
					
					// HEURISTIC 2 ================
					double minangle = 9999;
					for(Player oppositePlayer : pass.potentialReceiversOtherTeam){
						// if the opposite player is closer
						if(oppositePlayer.distanceToSender <
						   player.distanceToClosestOppositeTeamPlayer){
							// if the opposite player is between
							// (angle less than 30 degrees)
							double angle = calculateAngleThreePoints(
									pass.sender.x,
									pass.sender.y,
									player.x,
									player.y,
									oppositePlayer.x,
									oppositePlayer.y);
							
							// REMOVE THE SIGN
							angle = Math.abs(angle);
							
							if(angle >= 40){
								player.score -=900;
							}
							
							if(angle < minangle){
								minangle = angle;
							}
						}	
					}
					
//					if(minangle >= 10){
//						player.score -=50;
//					}
				}
				
				// Sort the players by distance to sender
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});

				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
				
			}
			System.out.println("=== PREDICTOR THREE (send to closest + penalty for opposite team player) + penalty for angle === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}
		
		// ==================================== //
		//====== PREDICTOR FOUR  (send to closest + penalty for opposite team player + forward) ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;
					
					// HEURISTIC! ================
					if(player.distanceToClosestOppositeTeamPlayer < 700){
						player.score += 900;
					}
					
					// HEURISTIC 4 ================
					// Find the team of the sender
					boolean senderIsFromFirstTeam = pass.sender.id <= 14;
					if(senderIsFromFirstTeam && player.y + pass.sender.y < 0 ){
						player.score += 1200;
					}
//					else if(player.x - pass.sender.x < 0 ){
//						player.score += 5000;
//					}
					
//					if(player.id <=5){
//						player.score -=200;
//					}
					
					
				}
				
				// Sort the players by score
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
			}
			System.out.println("=== PREDICTOR FOUR (to closest + forward (TENTATIVE) penalty for opposite team player) + penalty for angle === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			
			System.out.println(" THIS I DID NOT FINISH");
			System.out.println("=======================================");
		}
		// ==================================== //
		//====== PREDICTOR FIVE (send to closest + penalty for opposite team player + radius) ========== //
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;

					if(player.numberOppositeTeamPlayerWhithinRadius >= 1){
						player.score += 900 ;
					}
					
					if(player.numberOppositeTeamPlayerWhithinRadius >= 2){
						player.score += 55 ;
					}
				}
				
				// Sort the players by score
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
				}
				totalPredictions++;
				
			}
			System.out.println("=== PREDICTOR FIVE (send to closest + penalty for opposite team player) + radius count === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}

		// ==================================== //
		//====== PREDICTOR SIX + no repeated backpass
		// ==================================== //
		{
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double correctInThreePredictions = 0d;
			double totalPredictions  = 0d;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;

					if(player.numberOppositeTeamPlayerWhithinRadius >= 1){
						player.score += 900 ;
					}
					
					if(player.numberOppositeTeamPlayerWhithinRadius >= 2){
						player.score += 55 ;
					}
					
//					// NEW ================
//					// PUT A SMALL REWARD FOR SENDING BACK TO THE PREVIOUS
//					// SENDER
//					if(player.id == previousSender){
//						player.score -=85;
//					}
					
//					// NEW ================
//					// PUT A SMALL REWARD FOR SENDING BACK TO THE PREVIOUS
//					// SENDER
//					if(player.id == secondPreviousSender){
//						player.score -=5;
//					}
				}
				
				// Sort the players by score
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
					correctInThreePredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
					correctInThreePredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(2).id){
					correctInThreePredictions++;
				}
				totalPredictions++;
//				
//				secondPreviousSender = previousSender;
//				previousSender = pass.receiverId;
			}
			System.out.println("=== PREDICTOR SIX === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in three (all) : " + (correctInThreePredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println("=======================================");
		}
		// ==================================== //
		//====== PREDICTOR SEVEN + no repeated backpass + find pitch size
		// ==================================== //
		{
			
			
			// Calculate accuracy of simple predictor
			// Where the closest player from same team is predicted
			double correctPredictions = 0d;
			double correctInTwoPredictions = 0d;
			double correctInThreePredictions = 0d;
			double totalPredictions  = 0d;
			int previousSender = 999;
			for(Pass pass : passes){
				// ********************* *
				// IMPORTANT WE SKIP THE PREDICTION IF THE SENDER 
				// HAS NO POSITION IN THE DATA
				// ********************* *
				if(pass.sender == null){
					continue;
				}				
				
				// Calculate a score for each player
				for(Player player : pass.potentialReceiversSameTeam){
					player.score = player.distanceToSender;

					if(player.numberOppositeTeamPlayerWhithinRadius >= 1){
						player.score += 900 ;
					}
					
					if(player.numberOppositeTeamPlayerWhithinRadius >= 2){
						player.score += 55 ;
					}
					
					// NEW ================
					// PUT A SMALL REWARD FOR SENDING BACK TO THE PREVIOUS
					// SENDER
					if(player.id == previousSender){
						player.score -=85;
					}
//					
//					if(player == pass.leftMostPlayer){
//						player.score -=90;
//					}
					
//					// Calculate the vector of ball movement
					double xball = player.x - pass.sender.x;
					
					if(pass.senderIsLeftSide && xball < 0){
						player.score -= 0.3 * xball;
					}
					else if(xball >0){
						player.score += 0.1 * xball;
					}

					
					
//					if(xball < 100){
//						player.score -= 0.01*(player.x - pass.sender.x);
//					}
					
//					// NEW ================
//					// PUT A SMALL REWARD FOR SENDING BACK TO THE PREVIOUS
//					// SENDER
//					if(player.id == secondPreviousSender){
//						player.score -=5;
//					}
				}
				
				// Sort the players by score
				Collections.sort(pass.potentialReceiversSameTeam,
						new Comparator<Player>(){
							@Override
							public int compare(Player o1, Player o2) {
								return (int)( o1.score - o2.score);
							}});
				
				if(pass.receiverId == pass.potentialReceiversSameTeam.get(0).id){
					correctPredictions++;
					correctInTwoPredictions++;
					correctInThreePredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(1).id){
					correctInTwoPredictions++;
					correctInThreePredictions++;
				}else if(pass.receiverId == pass.potentialReceiversSameTeam.get(2).id){
					correctInThreePredictions++;
				}
				totalPredictions++;

				previousSender = pass.receiverId;
			}
			System.out.println("=== PREDICTOR SEVEN === ");
			System.out.println(" Accuracy (all) : " + (correctPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in two (all) : " + (correctInTwoPredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" Accuracy in three (all) : " + (correctInThreePredictions / (totalPredictions + numberOfSendersWithoutPosition) * 100.0));
			System.out.println(" THIS I DID NOT FINISH");
			System.out.println("=======================================");
		}
		
		
	}
	
	static  void print2dArrayWithoutIndex1(int[][] array){
		 for(int i = 1; i < array.length; i++){
                 for(int j = 1; j <array[i].length; j++){    
                     System.out.print(array[i][j] + " ");
             }
                 System.out.println(" ");
		 }
	}
	
	/**
	 * Calculate the eucledian distance between two vectors of doubles.
	 * @param vector1 the first vector
	 * @param vector2 the second vector
	 * @return the distance
	 */
	public static double calculateDistance(double x1, double y1, double x2, double y2) {
		double sum =0;	
		sum += Math.pow(x1 - x2, 2);
		sum += Math.pow(y1 - y2, 2);
		return Math.sqrt(sum);
	}
	
	/**
	 * Calculate the angle between three points P1, P2 and P3, where
	 * P1 is the origin (the point where the angle is)
	 * @param p1x
	 * @param p1y
	 * @param p2x
	 * @param p2y
	 * @param p3x
	 * @param p3y
	 * @return the angle
	 */
	public static double calculateAngleThreePoints(double p1x, double p1y, double p2x, double p2y, 
			double p3x, double p3y){
		double result = Math.atan2(p3y - p1y, p3x - p1x) -
                Math.atan2(p2y - p1y, p2x - p1x);
		return result;
	}
	
	public static void promptEnterKey(){
	    System.out.println("Press \"ENTER\" to continue...");
	    try {
	        System.in.read();
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}
}

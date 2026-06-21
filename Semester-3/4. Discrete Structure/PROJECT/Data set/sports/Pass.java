package sports;

import java.util.ArrayList;
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

public class Pass {

	// the time of the pass
	public long timeStart;
	public long timeEnd;
	
	// who sends and receives
	public int senderId;
	public int receiverId;
	public Player sender;
	public Player receiver;
	
	// the players on the field at that time that may receive the ball
	// (it excludes the sender)
	public List<Player> potentialReceivers = new ArrayList<Player>();
	public List<Player> potentialReceiversSameTeam = new ArrayList<Player>();
	public List<Player> potentialReceiversOtherTeam = new ArrayList<Player>();
	
	// Indicate if the corner of the sender team should be on the left side of the pitch 
	public boolean senderIsLeftSide;
	// The leftmost player in the field
	public Player leftMostPlayer;


	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer();
		buffer.append("time from: " + timeStart + " to: " + timeEnd + " ");
		buffer.append(" sender: " + senderId + " receiver: " + receiverId + " ");
		
		return buffer.toString();
	}
}

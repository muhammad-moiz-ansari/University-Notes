package sports;

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

public class Player {
	int id;
	double x;
	double y;
	double distanceToSender;
	double distanceToClosestOppositeTeamPlayer;
	double numberOppositeTeamPlayerWhithinRadius;
	
	double score;
	
	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer();
		buffer.append("(id: " + id + " x: " + x + " y: " + y 
				+ " dist to sender: " + distanceToSender + 
				 " dist to closest opposite team player: " + distanceToClosestOppositeTeamPlayer + ")");
		return buffer.toString();
	}
}

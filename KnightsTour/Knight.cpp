#include "Knight.h"

Knight::Knight()
{
	position = pos(4, 4);
	order = 1;
	//fill chessboard vector with 8x8 zeroes(unvisited) 
	for (int i = 0; i < 8; i++)
	{
		vector <int> val;
		for (int j = 0; j < 8; j++)
		{
			val.push_back(0);
		}
		chessboard.push_back(val);
	}
}

//loop through all 64 squares on chessboard and set to 0 (0 means unvisited)
void Knight::set_board()
{
	for (int i = 0; i < chessboard.size(); i++) {
		for (int j = 0; j < chessboard[i].size(); j++) {
			chessboard[i][j] = 0;
		}
	}
}

//loop through all 64 square values of a chessboard and print them to console
void Knight::print_board()
{
	cout << fixed << setprecision(2) << setfill('0'); //format print width to fixed width of 2
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << " | " << setw(2) << chessboard[i][j];
		}
		cout << " | " << endl;
	}
}

//Simulate knight's tour with given input, output both simple and complex solution onto console
void Knight::start_tour(int posx, int posy)
{
	//Execute simple solution with given input
	cout << "Simple Solution" << endl;
	set_board();
	this->position.setposx(posx);
	this->position.setposy(posy);
	order = 1;
	this->chessboard[position.getposx()][position.getposy()] = order; //fill starting point
	order++;

	while (order < 65) { //execute 63 times to fill entire chessboard
		position = get_next_pos_simple(position);
		this->chessboard[position.getposx()][position.getposy()] = order;
		order++;
	}

	if (checkSuccess()) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
	print_board();

	//Execute complex solution with given input
	cout << "Complex Solution" << endl;
	set_board();
	this->position.setposx(posx);
	this->position.setposy(posy);
	order = 1;
	this->chessboard[position.getposx()][position.getposy()] = order;
	order++;

	while (order < 65) {
		position = get_next_pos_complex(position);
		this->chessboard[position.getposx()][position.getposy()] = order;
		order++;
	}

	if (checkSuccess()) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "FAILURE" << endl;
	}
	print_board();

}

//returns a vector containing next legal positions given current position
vector<pos> Knight::get_valid_pos(pos current_pos)
{
	vector<pos> valid_pos;
	for (std::vector<pos>::iterator it = valid_moves.begin(); it != valid_moves.end(); ++it){
		pos new_pos = current_pos.add(*it);
		if (-1 < new_pos.getposx() && new_pos.getposx() < 8 && -1 < new_pos.getposy() && new_pos.getposy() < 8) { //check chessboard boundary condition
			if (this->chessboard[new_pos.getposx()][new_pos.getposy()] == 0) { //check if square has not been visited before
				valid_pos.push_back(new_pos);
			}
		}
	}
	return valid_pos;
}

//returns number of next legal moves given current position
int Knight::get_valid_pos_num(pos current_pos)
{
	vector<pos> valid_pos = get_valid_pos(current_pos);
	return valid_pos.size(); 
}

//simple solution to breaking ties : returns next position to move to
pos Knight::get_next_pos_simple(pos current_pos)
{
	vector<pos> valid_pos = get_valid_pos(current_pos);	//get pos vector of legal next positions
	int min = 8;
	pos next_pos;
	for (std::vector<pos>::iterator it = valid_pos.begin(); it != valid_pos.end(); ++it) { 
		int valid_pos_num = get_valid_pos_num(*it);
		if (valid_pos_num < min) { //among the legal next positions, find the position with the minimum number of legal moves
			min = valid_pos_num;
			next_pos = *it; //first to set the min value is the next position (simple solution)
		}
	}

	return next_pos;
}

//complex solution to breaking ties : returns next position to move to
pos Knight::get_next_pos_complex(pos current_pos)
{
	vector<pos> valid_pos = get_valid_pos(current_pos); 
	vector<pos> optimal_pos; //contains pos with minimum num of next legal pos
	pos next_pos;
	int min = 8;
	for (std::vector<pos>::iterator it = valid_pos.begin(); it != valid_pos.end(); ++it) {
		int valid_pos_num = get_valid_pos_num(*it);
		//only add pos with minimum num of next legal pos
		if (valid_pos_num < min) { //if new minimum has been discovered, set new minimum, and clear optimal_pos vector and start again
			optimal_pos.clear();
			optimal_pos.push_back(*it);
			min = valid_pos_num;
		}
		else if (valid_pos_num == min) { 
			optimal_pos.push_back(*it);
		}
	}

	//find pos with minimum sum of number of legal move
	int min2 = 64; 
	for (std::vector<pos>::iterator it = optimal_pos.begin(); it != optimal_pos.end(); ++it) { //loop through all pos in optimal_pos 
		int sum = 0; //find the sum of number of legal moves 
		vector<pos> valid_pos2 = get_valid_pos(*it);
		for (std::vector<pos>::iterator it2 = valid_pos2.begin(); it2 != valid_pos2.end(); ++it2) {
			int valid_pos_num = get_valid_pos_num(*it2);
			sum += valid_pos_num; //calculate sum of number of legal move for each legal move
		}
		if (sum < min2) { //set nextpos to legal move with minimum sum
			min2 = sum;
			next_pos = (*it);
		}
	}
	return next_pos;
}

//loop through all 64 square values of the chessboard, SUCCESS if none contains value 0
bool Knight::checkSuccess()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chessboard[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

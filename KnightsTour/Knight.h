//Knight class to replicate Knight's tour on 8x8 chessboard
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "pos.h" //created pos class to store x-position and y-position variables

using namespace std;

class Knight
{
	//member variables
private:
	int order; //order at which squares are visited
	pos position; //knight's posiiton on chessboard
	vector<vector<int>> chessboard; //2d vector of ints containing order at which it was visited
	vector<pos> valid_moves{pos(-2,1),pos(-1,2),pos(1,2),pos(2,1),pos(2,-1),pos(1,-2),pos(-1,-2),pos(-2,-1)}; //vector of predefined knight moves: clockwise starting from (-2,1)


public:
	//constructors
	Knight();

	//member functions
	void set_board(); //resets all  board values to 0
	void print_board(); //formats and prints chessboard onto console

	void start_tour(int posx = 4, int posy = 4); //Simulate knight's tour with given input, output both simple and complex solution onto console
	vector<pos> get_valid_pos(pos current_pos); //returns a vector containing next legal moves given current position
	int get_valid_pos_num(pos current_pos); //returns number of next legal moves given current position
	pos get_next_pos_simple(pos current_pos); //simple solution to breaking ties
	pos get_next_pos_complex(pos current_pos); //complex solution to breaking ties
	bool checkSuccess(); //check if success condition has been met
};

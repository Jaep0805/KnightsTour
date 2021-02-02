//Pos class to store x-position and y-position variables

#pragma once
class pos
{
private:
	//member variables
	int posx; //x-position
	int posy; //y-position

public:
	//constructors
	pos() { 
		this->posx = 4;
		this->posy = 4;
	};
	pos(int posx, int posy) {
		this->posx = posx;
		this->posy = posy;
	};

	//member functions
	//getters and setters
	int getposx();
	int getposy();
	void setposx(int x);
	void setposy(int y);

	//functions
	pos add(pos position); //return the vector sum of two pos class variables
};


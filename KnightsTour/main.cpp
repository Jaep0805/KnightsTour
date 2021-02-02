#include <iostream>
#include "Knight.h"

using namespace std;

int main() {
	Knight knight;

	//run knights tour for starting position (4,4)
	cout << "Starting point : (0,0)" << endl;
	knight.start_tour(0, 0);

	//run knights tour for all 64 starting positions
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << "//////////////////////////" << endl;
			cout << "Starting point : (" << i << "," << j <<")" << endl;
			knight.start_tour(i, j);
		}
	}*/

}
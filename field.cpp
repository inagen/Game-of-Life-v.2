#include "field.h"
#include <time.h>

Field::Field() {
	for(auto it = field.begin(); it != field.end(); it++) {
		*it = 0;
	} 
}

bool Field::getCell(int x, int y) const {

	if(x >= fieldWidth)
		x -= fieldWidth;
	if(x < 0)
		x += fieldWidth;

	if(y >= fieldHeight)
		y -= fieldHeight;
	if(y < 0)
		y += fieldHeight;

	x %= fieldWidth;
	y %= fieldHeight;
	return field[x + y * fieldWidth];
}

void Field::setCell(int x, int y, const bool& status) {

	x %= fieldWidth;
	y %= fieldHeight;
	field[x + y * fieldWidth] = status;
}

unsigned Field::getNumberOfNeighbors(int x, int y) const {

	unsigned numberOfNeighbors = 0;
	x %= fieldWidth;
	y %= fieldHeight;

	if(getCell(x, y + 1)) numberOfNeighbors++;
	if(getCell(x, y - 1)) numberOfNeighbors++;
	if(getCell(x + 1, y)) numberOfNeighbors++;
	if(getCell(x - 1, y)) numberOfNeighbors++;

	if(getCell(x + 1, y + 1)) numberOfNeighbors++;
	if(getCell(x + 1, y - 1)) numberOfNeighbors++;
	if(getCell(x - 1, y - 1)) numberOfNeighbors++;
	if(getCell(x - 1, y + 1)) numberOfNeighbors++;


	return numberOfNeighbors;  
}

void Field::setRandomField() {

	field = std::array<bool, fieldWidth*fieldHeight> ();
	srand(time(NULL));
	int N = rand() % (fieldWidth * fieldHeight / 10);
	for(int i(0); i < N; i++) {
		int x = rand() % fieldWidth;
		int y = rand() % fieldHeight;
		setCell(x, y, 1);
	}
}
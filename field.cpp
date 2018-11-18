#include "field.h"

Field::Field() {
	for(auto it = field.begin(); it != field.end(); it++) {
		*it = 0;
	} 
}

bool Field::getCell(unsigned x, unsigned y) const {

	if(x > fieldWidth)
		x -= fieldWidth;
	if(x < 0)
		x += fieldWidth;

	if(y > fieldHeight)
		y -= fieldHeight;
	if(y < 0)
		y += fieldHeight;

	return field[x + y * fieldWidth];
}

void Field::setCell(const unsigned& x, const unsigned& y, const bool& status) {
	field[x + y * fieldWidth] = status;
}

unsigned Field::getNumberOfNeighbors(const unsigned& x, const unsigned& y) const {
	unsigned numberOfNeighbors = 0;

	if (getCell(x, y + 1) == true) numberOfNeighbors++;
	if (getCell(x, y - 1) == true) numberOfNeighbors++;
	if (getCell(x + 1, y) == true) numberOfNeighbors++;
	if (getCell(x - 1, y) == true) numberOfNeighbors++;

	if (getCell(x + 1, y + 1) == true) numberOfNeighbors++;
	if (getCell(x + 1, y - 1) == true) numberOfNeighbors++;
	if (getCell(x - 1, y + 1) == true) numberOfNeighbors++;
	if (getCell(x - 1, y - 1) == true) numberOfNeighbors++;

	return numberOfNeighbors;  
}
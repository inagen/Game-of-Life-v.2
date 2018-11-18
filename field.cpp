#include "field.h"

Field::Field() {
	for(auto it = field.begin(); it != field.end(); it++) {
		*it = 0;
	} 
}

std::array<bool, fieldWidth*fieldHeight> Field::getField() const {
	return this->field;
}

bool Field::getCell(unsigned x, unsigned y) const {

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

void Field::setCell(unsigned x, unsigned y, const bool& status) {

	x %= fieldWidth;
	y %= fieldHeight;
	field[x + y * fieldWidth] = status;
}

unsigned Field::getNumberOfNeighbors(unsigned x, unsigned y) const {

	unsigned numberOfNeighbors = 0;
	x %= fieldWidth;
	y %= fieldHeight;

	for (int xs = -1; xs <= 1; ++xs) {
  		for (int ys = -1; ys <= 1; ++ys) {
    		if (this->getCell(x + xs, y + ys)) numberOfNeighbors++;
  		}
	}

	return numberOfNeighbors;  
}

void Field::setRandomField() {

	srand(time(NULL));
	int N = rand() % (fieldWidth * fieldHeight / 10);
	for(int i(0); i < N; i++) {
		int x = rand() % fieldWidth;
		int y = rand() % fieldHeight;
		this->setCell(x, y, 1);
	}
}
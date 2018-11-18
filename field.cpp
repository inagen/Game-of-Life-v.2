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

	if (this->getCell(x, y + 1) == true) numberOfNeighbors++;
	if (this->getCell(x, y - 1) == true) numberOfNeighbors++;
	if (this->getCell(x + 1, y) == true) numberOfNeighbors++;
	if (this->getCell(x - 1, y) == true) numberOfNeighbors++;

	if (this->getCell(x + 1, y + 1) == true) numberOfNeighbors++;
	if (this->getCell(x + 1, y - 1) == true) numberOfNeighbors++;
	if (this->getCell(x - 1, y + 1) == true) numberOfNeighbors++;
	if (this->getCell(x - 1, y - 1) == true) numberOfNeighbors++;

	return numberOfNeighbors;  
}

void Field::calculateAndChangeCellStatus(unsigned x, unsigned y) {

	auto numberOfNeighbors = this->getNumberOfNeighbors(x, y);
	if (numberOfNeighbors > 3 || numberOfNeighbors < 2)
		this->setCell(x, y, false);
	else
		this->setCell(x, y, true);
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
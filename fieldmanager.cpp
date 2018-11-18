#include "fieldmanager.h"

void FieldManager::proccessField() {
	fieldCopy = field;
	for(int y(0); y < fieldWidth; y++) {
		for(int x(0); x < fieldHeight; x++) {
			calculateAndChangeCellStatus(x, y); 
		}
	}
	field = fieldCopy;
} 

void FieldManager::fieldReset() {
	field = Field();
	field.setRandomField();
	fieldCopy = Field();
}


void FieldManager::calculateAndChangeCellStatus(int x, int y) {
	auto numberOfNeighbors = field.getNumberOfNeighbors(x, y);
	fieldCopy.setCell(x, y, numberOfNeighbors <= 3 && numberOfNeighbors >= 2);
}

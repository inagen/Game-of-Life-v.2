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
	if(numberOfNeighbors < 2 || numberOfNeighbors > 3)
		fieldCopy.setCell(x, y, false);
	else if(numberOfNeighbors == 3)
		fieldCopy.setCell(x, y, true);
}

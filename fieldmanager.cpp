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
	fieldCopy = Field();
}


void FieldManager::calculateAndChangeCellStatus(unsigned x, unsigned y) {

	auto numberOfNeighbors = field.getNumberOfNeighbors(x, y);
	if (numberOfNeighbors > 3 || numberOfNeighbors < 2)
		fieldCopy.setCell(x, y, false);
	else
		fieldCopy.setCell(x, y, true);
}

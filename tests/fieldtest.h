#pragma once
#include "../field.h"
#include <iostream>
#include <time.h>

void printField(Field& field) {
	std::cout << " _|0 1 2 3 4 5 6 7 8 9" << std::endl;
	for (int i(0); i < fieldWidth; i++) {
		std::cout << i << " |";
		for(int j(0); j < fieldHeight; j++) {
			std::cout << field.getCell(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void fieldTest(Field field) {
	field.setRandomField();
	printField(field);

	srand(time(NULL));
	int x = rand() % fieldWidth;
	int y = rand() % fieldHeight;
	field.calculateAndChangeCellStatus(x, y);
	
	std::cout << std::endl;
	std::cout << x << ":" << y << " living neighbors: " << field.getNumberOfNeighbors(x, y) << std::endl;
	std::cout << std::endl;
	printField(field);
}
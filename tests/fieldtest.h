#pragma once
#include "../field.h"
#include <iostream>
#include <time.h>

void printField(Field& field) {
	for (int i(0); i < fieldWidth; i++) {
		for(int j(0); j < fieldHeight; j++) {
			std::cout << field.getCell(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void setRandomField(Field& field) {
	srand(time(NULL));
	int N = rand() % (fieldWidth * fieldHeight);
	for(int i(0); i < N; i++) {
		int x = rand() % fieldWidth;
		int y = rand() % fieldHeight;
		field.setCell(x, y, 1);
	}
}

void fieldTest() {
	Field field;
	setRandomField(field);
	printField(field);

	int x = rand() % fieldWidth;
	int y = rand() % fieldHeight;

	std::cout << std::endl;
	std::cout << x << ":" << y << " living neighbors: " << field.getNumberOfNeighbors(x, y) << std::endl;
}
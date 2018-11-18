#pragma once
#include "../fieldmanager.h"
#include <unistd.h>
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

void fieldManagerTest2() {
	FieldManager fieldManager;
	fieldManager.field.setRandomField();
	for(int i(0); i< 100; i++) {
		printField(fieldManager.field);
		fieldManager.proccessField();
		usleep(500000);
		system("clear");
	}	
}

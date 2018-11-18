#pragma once
#include "../fieldmanager.h"
#include "fieldtest.h"
#include <unistd.h>

void fieldManagerTest() {
	FieldManager fieldManager;
	fieldManager.field.setRandomField();
	printField(fieldManager.field);
	std::cout << std::endl << std::endl;
	fieldManager.proccessField();
	printField(fieldManager.field);
}

void fieldManagerTest2() {
	FieldManager fieldManager;
	fieldManager.field.setRandomField();
	for(int i(0); i< 100; i++) {
		printField(fieldManager.field);
		fieldManager.proccessField();
		sleep(1);
		system("clear");
	}	
}

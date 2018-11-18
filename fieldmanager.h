#pragma once
#include "field.h" 

class FieldManager {
public:
	Field field;

private:
	Field fieldCopy;

public:
	FieldManager() : field(), fieldCopy() {};
	void proccessField();
	void fieldReset();

private:
	void calculateAndChangeCellStatus(int, int);
};
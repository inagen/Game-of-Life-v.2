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
	void setRandomField();
	void resetField();

private:
	void calculateAndChangeCellStatus(int, int);
};
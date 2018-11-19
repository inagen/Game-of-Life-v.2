#pragma once
#include <array>

constexpr unsigned fieldWidth  = 20;
constexpr unsigned fieldHeight = 20;


class Field {
private:
	std::array<bool, fieldWidth*fieldHeight> field;

public:
	Field();
	bool getCell(int, int) const;
	void setCell(int, int, const bool&);
	unsigned getNumberOfNeighbors(int, int) const;
	void setRandomField();
};
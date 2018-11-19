#pragma once
#include <array>

constexpr unsigned fieldWidth  = 100;
constexpr unsigned fieldHeight = 100;


class Field {
private:
	std::array<bool, fieldWidth*fieldHeight> field;

public:
	Field();
	std::array<bool, fieldWidth*fieldHeight> getField() const;
	bool getCell(int, int) const;
	void setCell(int, int, const bool&);
	unsigned getNumberOfNeighbors(int, int) const;
	void setRandomField();
};
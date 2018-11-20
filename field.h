#pragma once
#include <array>

constexpr unsigned fieldWidth  = 128;
constexpr unsigned fieldHeight = 128;


class Field {
public:
	std::array<bool, fieldWidth*fieldHeight> field;

public:
	Field();
	bool getCell(int, int) const;
	void setCell(int, int, const bool&);
	unsigned getNumberOfNeighbors(int, int) const;
	void setRandomField();
};
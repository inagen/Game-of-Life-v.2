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
	bool getCell(unsigned, unsigned) const;
	void setCell(unsigned, unsigned, const bool&);
	unsigned getNumberOfNeighbors(unsigned, unsigned) const;
	void setRandomField();
};
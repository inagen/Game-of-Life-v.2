#pragma once
#include <array>

constexpr unsigned fieldWidth  = 10;
constexpr unsigned fieldHeight = 10;


class Field {
private:
	std::array<bool, fieldWidth*fieldHeight> field;

public:
	Field();
	std::array<bool, fieldWidth*fieldHeight> getField() const;
	bool getCell(unsigned, unsigned) const;
	void setCell(unsigned, unsigned, const bool&);
	unsigned getNumberOfNeighbors(unsigned, unsigned) const;
	void calculateAndChangeCellStatus(unsigned, unsigned);
	void setRandomField();
};
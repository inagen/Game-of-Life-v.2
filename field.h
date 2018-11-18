#pragma once
#include <array>

constexpr unsigned fieldWidth  = 10;
constexpr unsigned fieldHeight = 10;


class Field {
private:
	std::array<bool, fieldWidth*fieldHeight> field;

public:
	Field();
	bool getCell(unsigned, unsigned) const;
	void setCell(const unsigned&, const unsigned&, const bool&);
	unsigned getNumberOfNeighbors(const unsigned&, const unsigned&) const;
};
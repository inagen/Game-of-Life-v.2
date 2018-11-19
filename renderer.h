#pragma once
#include <SFML/Graphics.hpp>
#include "fieldmanager.h"

constexpr unsigned cellSize     = 10;
constexpr unsigned windowWidth  = fieldWidth*(cellSize);
constexpr unsigned windowHeight = fieldHeight*(cellSize);

class Renderer {
private:
	FieldManager fieldManager;
	std::array<sf::RectangleShape, fieldWidth*fieldHeight> shapes;
	sf::RenderWindow* window;
public:
	Renderer();
	void mainLoop();
private:
	void draw();
};
#pragma once
#include <SFML/Graphics.hpp>
#include "fieldmanager.h"

constexpr unsigned cellSize     = 5;
constexpr unsigned windowWidth  = fieldWidth*(cellSize+1);
constexpr unsigned windowHeight = fieldHeight*(cellSize+1);



class Renderer {
private:
	FieldManager fieldManager;
	std::array<sf::RectangleShape, fieldWidth*fieldHeight> shapes;
	sf::RenderWindow* window;
public:
	Renderer();
	void mainLoop();
};
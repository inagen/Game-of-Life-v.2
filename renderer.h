#pragma once
#include <SFML/Graphics.hpp>
#include "fieldmanager.h"

constexpr unsigned cellSize     = 5;
constexpr unsigned windowWidth  = fieldWidth*(cellSize);
constexpr unsigned windowHeight = fieldHeight*(cellSize);

class Renderer {
private:
	FieldManager fieldManager;
	sf::RenderWindow* window;
	sf::Texture texture;
	bool isPause;
public:
	Renderer();
	void mainLoop();
private:
	void mouseClick(int, int);
	void drawCell();
	void draw();
};
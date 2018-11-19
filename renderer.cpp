#include "renderer.h"
#include <time.h>

Renderer::Renderer() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
	fieldManager.field.setRandomField();
}

void Renderer::mainLoop() {
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
				fieldManager.field.setRandomField();
		}
		draw();
		fieldManager.proccessField();
		window->clear();
	}
}

void Renderer::draw() {
	for(int i(0); i < windowWidth; i++) {
		for (int j(0); j < windowHeight; j++) {
			int x = i;
			int y = j;
			x %= fieldWidth;
			y %= fieldHeight;

			shapes[x + y * fieldWidth] = sf::RectangleShape(sf::Vector2f(cellSize, cellSize));
			shapes[x + y * fieldWidth].setPosition(i*cellSize, j*cellSize);

			if(fieldManager.field.getCell(x, y))
				(shapes[x + y * fieldWidth]).setFillColor(sf::Color::White);
			else 
				(shapes[x + y * fieldWidth]).setFillColor(sf::Color(55, 55, 55));

			window->draw(shapes[x + y * fieldWidth]);
		}
	}
	window->display();
}

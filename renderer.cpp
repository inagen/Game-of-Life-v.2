#include "renderer.h"
#include <time.h>

Renderer::Renderer() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
	fieldManager.field.setRandomField();
	isPause = false;
}

void Renderer::mainLoop() {
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !isPause)
				fieldManager.field.setRandomField();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
				isPause = !isPause;
		}
		if (!isPause) {
			draw();
			fieldManager.proccessField();
			window->clear(); 
		}
	}
}

void Renderer::draw() {
	for(int i(0); i < windowWidth; i++) {
		for (int j(0); j < windowHeight; j++) {
			int x = i;
			int y = j;
			x %= fieldWidth;
			y %= fieldHeight;

			sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
			cell.setPosition(i*cellSize, j*cellSize);

			if(fieldManager.field.getCell(x, y))
				cell.setFillColor(sf::Color::White);
			else 
				cell.setFillColor(sf::Color(55, 55, 55));

			window->draw(cell);
		}
	}
	window->display();
}

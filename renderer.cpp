#include "renderer.h"
#include <time.h>
#include <iostream>

Renderer::Renderer() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
	window->setFramerateLimit(25);
	fieldManager.field.setRandomField();

	isPause = false;

	sf::Image image;
	image.create(fieldWidth, fieldHeight, sf::Color(40, 40, 40));
	texture.loadFromImage(image, sf::IntRect());
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
				fieldManager.resetField();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5) && !isPause)
				fieldManager.field.setRandomField();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
				isPause = !isPause;

			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					mouseClick(event.mouseButton.x, event.mouseButton.y);
		}
		if (!isPause) {
			fieldManager.proccessField();
			draw();
			window->clear(); 
		}
	}
}

void Renderer::draw() {
	drawCells();
	window->display();
}

void Renderer::drawCells() {
	sf::Image image;
	image.create(fieldWidth, fieldHeight, sf::Color(40, 40, 40));

	for(int i(0); i < windowWidth; i++) {
		for (int j(0); j < windowHeight; j++) {
			int x = i;
			int y = j;
			x %= fieldWidth;
			y %= fieldHeight;

			if(fieldManager.field.getCell(x, y))
				image.setPixel(x, y, sf::Color::White);
		}
	} 
	texture.update(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(cellSize, cellSize);
	window->draw(sprite);
}

void Renderer::mouseClick(int x, int y) {
	if (x < 0 || y < 0)
		return;
	int columnWidth = window->getSize().x / fieldWidth;
	int rowHeight = window->getSize().y / fieldHeight;

	const unsigned cellX = x / columnWidth;
	const unsigned cellY = y / rowHeight;

	bool currentCellStatus = fieldManager.field.getCell(cellX, cellY);
	fieldManager.field.setCell(cellX, cellY, !currentCellStatus);
	draw();
}



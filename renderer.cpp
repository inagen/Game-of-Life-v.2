#include "renderer.h"
#include <time.h>

Renderer::Renderer() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
	window->setFramerateLimit(25);
	fieldManager.field.setRandomField();

	isPause = false;
	gridIsShown = true;

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
	drawCell();
	window->display();
}

void Renderer::drawCell() {
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


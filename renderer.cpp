#include "renderer.h"

Renderer::Renderer() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game of Life");
}

void Renderer::mainLoop() {
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		draw();
		usleep(50000);
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

			shapes[x + y * fieldWidth] = sf::RectangleShape(sf::Vector2f(5, 5));
			shapes[x + y * fieldWidth].setPosition(i*5, j*5);

			if(fieldManager.field.getCell(x, y))
				(shapes[x + y * fieldWidth]).setFillColor(sf::Color::White);
			else 
				(shapes[x + y * fieldWidth]).setFillColor(sf::Color::Black);

			window->draw(shapes[x + y * fieldWidth]);
		}
	}
	window->display();
	window->clear();
}

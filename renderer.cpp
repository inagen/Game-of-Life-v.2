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
		window->clear();
		///
		window->display();
	}
}
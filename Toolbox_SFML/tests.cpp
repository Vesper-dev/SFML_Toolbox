#include "Source files\Toolbox.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Toolbox::TextButton button(window, sf::Vector2f(100, 100), "Przycisk");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			button.update(event);
		}

		window.clear(sf::Color::White);
		button.draw();
		window.display();
	}
}
#include "Source files\Toolbox.h"

void pressKey(sf::Event &event, sf::Keyboard::Key key)
{
	event.type = sf::Event::KeyPressed;
	event.key.code = key;
}

void pressMouseButton(sf::Event &event)
{
	event.type = sf::Event::MouseButtonReleased;
	event.mouseButton.button = sf::Mouse::Left;
}

bool textButtonTest(sf::RenderWindow &window, sf::Event &event, Toolbox::TextButton &button)
{
	button.setPosition(sf::Vector2f(100,100));
	sf::Mouse::setPosition(sf::Vector2i(0, 0), window);
	button.update(event);
	if (button.isButtonSelected() == false && button.isButtonEnabled() == false){
		sf::Mouse::setPosition(sf::Vector2i(130, 115), window);
		button.update(event);
		if (button.isButtonSelected() == true){
			pressKey(event, sf::Keyboard::Return);
			button.update(event);
			if(button.isButtonEnabled() == true){
				pressMouseButton(event);
				button.update(event);
				if (button.isButtonEnabled() == false) {
					return true;
				}
				std::cerr << "Error: Could not enabled button with mouse\n";
				return false;
			}
			std::cerr << "Error: Could not enabled button with keyboard\n";
			return false;
		}
		std::cerr << "Error: Mouse could not selected text button or mouse is disabled\n";
		return false;
	}
	std::cerr << "Error: Wrong input data for text button \n";
	return false;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Toolbox::TextButton button(window, sf::Vector2f(100, 100), "Przycisk");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.type == sf::Event::Closed)
				window.close();
			if (textButtonTest(window, event, button) == true)
				std::cout << "All test OK\n";
			else
				std::cout << "TextBox test failed";
			window.close();
			button.update(event);
		}

		window.clear(sf::Color::White);
		button.draw();
		window.display();
	}
	std::cin.get();
}
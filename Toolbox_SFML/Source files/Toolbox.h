#pragma once
#include "SFML\Graphics.hpp"
#include "Button.h"
#include <string>
#include <iostream>

class Toolbox
{
public:
	class TextButton :public Button
	{
		void setPrimaryDimensions(sf::RenderWindow &_window, const sf::Vector2f _position, const std::string _name);
		void updateMouse(sf::Event &_event);
		bool isMouseOnButton();
		void updateMouseButton(sf::Event &_event);
		void updateKeyboard(sf::Event &_event);
		bool isKeyPressed(sf::Event &_event)const;
		void changeButtonState();
		void updateTextColor();
		std::string name;
		sf::Font font;
		sf::Text text;
		sf::Color textColor, selectedTextColor;
	public:
		TextButton(sf::RenderWindow &_window, const sf::Vector2f _position, const std::string _name);
		void setTextOptions(const std::string _fontName, const sf::Color _textColor, const sf::Color _selectedTextColor, const int _fontSize);
		void setTextColor(const sf::Color _color);
		void setSelectedTextColor(const sf::Color _color);
		void update(sf::Event &_event);
		void draw();
	};
};
#include "Toolbox.h"

void Toolbox::TextButton::setPrimaryDimensions
(sf::RenderWindow &_window, const sf::Vector2f _position, const std::string _name)
{
	window = &_window;
	position = _position;
	name = _name;
	key = sf::Keyboard::Return;
}

void Toolbox::TextButton::updateTextColor()
{
	if (isSelected == true)
		text.setColor(selectedTextColor);
	else
		text.setColor(textColor);
}

Toolbox::TextButton::TextButton
(sf::RenderWindow &_window, const sf::Vector2f _position, const std::string _name)
{
	clearAllStates();
	setPrimaryDimensions(_window, _position, _name);
	setTextOptions("OpenSans-Bold.ttf", sf::Color::Black, sf::Color::Blue, 30);
}

void Toolbox::TextButton::setTextOptions
(const std::string _fontName, const sf::Color _textColor, const sf::Color _selectedTextColor, const int _fontSize)
{
	if (font.loadFromFile(_fontName) == false)
		std::cerr << "Could not open font: " << _fontName << "\n";
	text = sf::Text(name, font, _fontSize);
	text.setPosition(position);
	textColor = _textColor;
	selectedTextColor = _selectedTextColor;
	text.setColor(textColor);
}

void Toolbox::TextButton::setTextColor
(const sf::Color _color)
{
	textColor = _color;
}

void Toolbox::TextButton::setSelectedTextColor
(const sf::Color _color)
{
	selectedTextColor = _color;
}

void Toolbox::TextButton::update
(sf::Event &_event)
{
	updateMouse(_event, text);
	updateKeyboard(_event);
	updateTextColor();
	text.setPosition(position);
}

void Toolbox::TextButton::draw()
{
	window->draw(text);
}
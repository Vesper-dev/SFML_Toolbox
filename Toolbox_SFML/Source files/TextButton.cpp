#include "Toolbox.h"

void Toolbox::TextButton::setPrimaryDimensions
(sf::RenderWindow &_window, const sf::Vector2f _position, const std::string _name)
{
	window = &_window;
	position = _position;
	name = _name;
}

void Toolbox::TextButton::updateMouse
(sf::Event &_event)
{
	if (isMouseActive == true && isMouseOnButton() == true)
		updateMouseButton(_event);
}

bool Toolbox::TextButton::isMouseOnButton()
{
	sf::Vector2f mousePosition{ sf::Vector2f(sf::Mouse::getPosition(*window)) };
	if (text.getGlobalBounds().contains(mousePosition) == true) {
		isSelected = true;
		return true;
	}
	isSelected = false;
	return false;
}

void Toolbox::TextButton::updateMouseButton
(sf::Event &_event)
{
	if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Left)
		changeButtonState();
}

void Toolbox::TextButton::updateKeyboard
(sf::Event &_event)
{
	if (isKeyPressed(_event) == true && _event.key.code == sf::Keyboard::Return)
		changeButtonState();
}

bool Toolbox::TextButton::isKeyPressed
(sf::Event &_event)const
{
	if (isKeyboardActive == true && isSelected == true && _event.type == sf::Event::KeyPressed)
		return true;
	return false;
}

void Toolbox::TextButton::changeButtonState()
{
	isLaunched = isLaunched ? false : true;
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
	updateMouse(_event);
	updateKeyboard(_event);
	updateTextColor();
}

void Toolbox::TextButton::draw()
{
	window->draw(text);
}
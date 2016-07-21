#include "Toolbox.h"

void Toolbox::TextureButton::setPrimaryDimensions
(sf::RenderWindow &_window, const sf::Vector2f _position, const sf::Texture &_selected, const sf::Texture &_unselected)
{
	window = &_window;
	position = _position;
	selected.setTexture(_selected);
	unselected.setTexture(_unselected);
	key = sf::Keyboard::Return;
}

Toolbox::TextureButton::TextureButton
(sf::RenderWindow &_window, const sf::Vector2f _position, const sf::Texture &_selected, const sf::Texture &_unselected)
{
	clearAllStates();
	setPrimaryDimensions(_window, _position, _selected, _unselected);
	selected.setPosition(position);
	unselected.setPosition(position);
}

void Toolbox::TextureButton::setButtonTexture
(sf::Texture &_newTexture)
{
	selected.setTexture(_newTexture);
}
void Toolbox::TextureButton::setSelectedButtonTexture
(sf::Texture &_newTexture)
{
	unselected.setTexture(_newTexture);
}

void Toolbox::TextureButton::update
(sf::Event &_event)
{
	updateMouse(_event, selected);
	updateMouse(_event, unselected);
	updateKeyboard(_event);
	selected.setPosition(position);
	unselected.setPosition(position);
}
void Toolbox::TextureButton::draw()
{
	if (isSelected == true)
		window->draw(unselected);
	else
		window->draw(selected);
}
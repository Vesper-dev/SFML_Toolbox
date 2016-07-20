#pragma once
#include "SFML\Graphics.hpp"

class Button
{
public:
	void setMouseState(const bool _newState)
	{
		isMouseActive = _newState;
	}
	void setKeyboardState(const bool _newState)
	{
		isKeyboardActive = _newState;
	}
	void setSelectingKey(const sf::Keyboard::Key _newSelectingKey)
	{
		key = _newSelectingKey;
	}
	void setSelectedState(const bool _newState)
	{
		isSelected = _newState;
	}
	void setButtonState(const bool _newState)
	{
		isLaunched = _newState;
	}
	void setPosition(const sf::Vector2f _newState)
	{
		position = _newState;
	}
	sf::Vector2f getPosition()
	{
		return position;
	}
	bool isButtonEnabled()const
	{
		return isLaunched;
	}
	bool isButtonSelected()const
	{
		return isSelected;
	}
protected:
	sf::RenderWindow *window;
	sf::Vector2f position;
	sf::Keyboard::Key key;
	bool isMouseActive;
	bool isKeyboardActive;
	bool isSelected;
	bool isLaunched;
	void clearAllStates()
	{
		isMouseActive = true;
		isKeyboardActive = true;
		isSelected = false;
		isLaunched = false;
	}
	void updateMouse(sf::Event &_event, sf::Text &_text)
	{
		if (isMouseActive == true && isMouseOnButton(_text) == true)
			updateMouseButton(_event);
	}
	void updateMouse(sf::Event &_event, sf::Sprite &_sprite)
	{
		if (isMouseActive == true && isMouseOnButton(_sprite) == true)
			updateMouseButton(_event);
	}
	bool isMouseOnButton(sf::Text &_text)
	{
		sf::Vector2f mousePosition{ sf::Vector2f(sf::Mouse::getPosition(*window)) };
		if (_text.getGlobalBounds().contains(mousePosition) == true) {
			isSelected = true;
			return true;
		}
		isSelected = false;
		return false;
	}
	bool isMouseOnButton(sf::Sprite &_sprite)
	{
		sf::Vector2f mousePosition{ sf::Vector2f(sf::Mouse::getPosition(*window)) };
		if (_sprite.getGlobalBounds().contains(mousePosition) == true) {
			isSelected = true;
			return true;
		}
		isSelected = false;
		return false;
	}
	void updateMouseButton(sf::Event &_event)
	{
		if (_event.type == sf::Event::MouseButtonReleased && _event.mouseButton.button == sf::Mouse::Left)
			changeButtonState();
	}
	void updateKeyboard(sf::Event &_event)
	{
		if (isKeyPressed(_event) == true && _event.key.code == key)
			changeButtonState();
	}
	bool isKeyPressed(sf::Event &_event)const
	{
		if (isKeyboardActive == true && isSelected == true && _event.type == sf::Event::KeyPressed)
			return true;
		return false;
	}
	void changeButtonState()
	{
		isLaunched = isLaunched ? false : true;
	}
};
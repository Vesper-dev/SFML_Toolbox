#pragma once
#include "SFML\Graphics.hpp"

class Button
{
public:
	void setMouseState(bool newState)
	{
		isMouseActive = newState;
	}
	void setKeyboardState(bool newState)
	{
		isKeyboardActive = newState;
	}
	void setSelectedState(bool newState)
	{
		isSelected = newState;
	}
	void setButtonState(bool newState)
	{
		isLaunched = newState;
	}
	void setPosition(sf::Vector2f _position)
	{
		isChangeToUpdate = true;
		position = _position;
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
	bool isChangeToUpdate;
	void clearAllStates()
	{
		isMouseActive = true;
		isKeyboardActive = true;
		isSelected = false;
		isLaunched = false;
		isChangeToUpdate = false;
	}
};
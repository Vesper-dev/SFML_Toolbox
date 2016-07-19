#pragma once
#include "SFML\Graphics.hpp"

class Button
{
public:
	void setMouseState(bool _newState)
	{
		isMouseActive = _newState;
	}
	void setKeyboardState(bool _newState)
	{
		isKeyboardActive = _newState;
	}
	void setSelectedState(bool _newState)
	{
		isSelected = _newState;
	}
	void setButtonState(bool _newState)
	{
		isLaunched = _newState;
	}
	void setPosition(sf::Vector2f _newState)
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
};
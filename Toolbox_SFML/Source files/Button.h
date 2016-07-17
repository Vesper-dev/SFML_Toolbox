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
	bool isMouseActive;
	bool isKeyboardActive;
	bool isSelected;
	bool isLaunched;
	void clearAllStates()
	{
		isMouseActive = true;
		isKeyboardActive = true;
		isSelected = true;
		isLaunched = true;
	}
};
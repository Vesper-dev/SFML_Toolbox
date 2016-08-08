#pragma once
#include "SFML\Graphics.hpp"
//#include "Toolbox.h"

using namespace sf;
class Button 
{
public:
    Button(RenderWindow& _window)
    {
        isMouseActive = true;
        isKeyboardActive = true;
        isSelected = false;
        isLaunched = false;
        window = &_window;
    }

	void setMouseState(const bool _newState)
	{
		isMouseActive = _newState;
	}

	void setKeyboardState(const bool _newState)
	{
		isKeyboardActive = _newState;
	}

	void setSelectingKey(const Keyboard::Key _newSelectingKey)
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

	bool isButtonEnabled()const
	{
		return isLaunched;
	}

	bool isButtonSelected()const
	{
		return isSelected;
	}

protected:
	RenderWindow *window;
	Keyboard::Key key;
	bool isMouseActive;
	bool isKeyboardActive;
	bool isSelected;
	bool isLaunched;

	void updateMouse(Event &_event, bool isMouseSelecting)
	{
        if (isMouseActive) {
            if (isMouseSelecting == true) {
                updateMouseButton(_event);
                isSelected = true;
            }
            else {
                updateMouseButton(_event);
                isSelected = false;
            }
        }
	}

	bool isMouseOnButton(Sprite &_sprite)
	{
		Vector2f mousePosition{ Vector2f(Mouse::getPosition(*window)) };
		if (_sprite.getGlobalBounds().contains(mousePosition) == true) {
			isSelected = true;
			return true;
		}
		isSelected = false;
		return false;
	}

	void updateMouseButton(Event &_event)
	{
		if (_event.type == Event::MouseButtonReleased && _event.mouseButton.button == Mouse::Left)
			changeButtonState();
	}

	void updateKeyboard(Event &_event)
	{
		if (isKeyPressed(_event) == true && _event.key.code == key)
			changeButtonState();
	}

	bool isKeyPressed(Event &_event)const
	{
		if (isKeyboardActive == true && isSelected == true && _event.type == Event::KeyPressed)
			return true;
		return false;
	}

	void changeButtonState()
	{
		isLaunched = isLaunched ? false : true;
	}
};
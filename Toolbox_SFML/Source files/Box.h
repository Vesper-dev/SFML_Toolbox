#pragma once
#include "SFML\Graphics.hpp"

class Box
{
public:
	void setPosition(const sf::Vector2f _newState)
	{
		position = _newState;
	}
	sf::Vector2f getPosition()
	{
		return position;
	}
protected:
	sf::RenderWindow *window;
	sf::Vector2f position;
};
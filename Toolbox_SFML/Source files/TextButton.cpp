#include "Toolbox.h"

using namespace tb;

void TextButton::updateColor()
{
    if (isSelected == false && getColor() == latterColor)
        setColor(primaryColor);
    if (isSelected == true) 
        setColor(latterColor);
    else 
        primaryColor = getColor();
}

void TextButton::setLatterColor
(const Color &_color)
{
	latterColor = _color;
}

const Color& TextButton::getLatterColor()
{
    return latterColor;
}

bool TextButton::isMouseSelecting()
{
    Vector2f mousePosition{ Vector2f(Mouse::getPosition(*window)) };
    return getGlobalBounds().contains(mousePosition);
}

void TextButton::update
(Event &_event)
{
	updateMouse(_event, isMouseSelecting());
	updateKeyboard(_event);
	updateColor();
}

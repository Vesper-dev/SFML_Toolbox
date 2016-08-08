#include "Toolbox.h"

using namespace tb;

void TextureButton::updateTexture()
{
    if (isSelected == false && getTexture() == &latterTexture)
        setTexture(primaryTexture);
    if (isSelected == true)
        setTexture(latterTexture);
    else
        primaryTexture = *getTexture();
}

void TextureButton::setLatterTexture(const sf::Texture &_texture)
{
    latterTexture = _texture;
}

const Texture& TextureButton::getLatterTexture()
{
    return latterTexture;
}

bool TextureButton::isMouseSelecting()
{
    Vector2f mousePosition{ Vector2f(Mouse::getPosition(*window)) };
    return getGlobalBounds().contains(mousePosition);
}

void TextureButton::update(sf::Event &_event)
{
	updateMouse(_event, isMouseSelecting());
	updateKeyboard(_event);
}

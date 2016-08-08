#pragma once
#include "Button.h"
#include <string>
#include <iostream>

using namespace sf;

namespace tb
{
    class TextButton :public Text, public Button
    {
        void updateColor();
        Color primaryColor, latterColor;
    public:
        TextButton(RenderWindow &_window, const String &string, const Font &font, unsigned int characterSize = 30)
            : Text{ string, font, characterSize }, Button{ _window }, latterColor{ Color::Blue }, primaryColor{Color::White} {}
        TextButton(RenderWindow &window) :Text{}, Button{ window }, latterColor{ Color::Blue }, primaryColor{ Color::White } {}
		void setLatterColor(const Color &_color);
        const Color& getLatterColor();
        bool isMouseSelecting();
		void update(Event &_event);
	};
	class TextureButton :public Sprite, public Button
	{
        void updateTexture();
		Texture primaryTexture, latterTexture;
	public:
        TextureButton(sf::RenderWindow &_window) :Sprite(), Button(_window) {}
        TextureButton(sf::RenderWindow &_window, const Texture &_primary, const Texture &_latter) :Sprite(_primary), Button(_window),
            primaryTexture{ _primary }, latterTexture{_latter} {}
        void setLatterTexture(const sf::Texture &_texture); 
        const Texture& getLatterTexture();
        bool isMouseSelecting();
		void update(sf::Event &_event);
	};
	class Label :public Text
	{
        Label(String &string, const Font &font, unsigned int characterSize = 30)
            : Text{ string, font, characterSize }{}
        Label(RenderWindow &window) :Text() {}
	};
	class TextBox :public Text
	{
	};
}
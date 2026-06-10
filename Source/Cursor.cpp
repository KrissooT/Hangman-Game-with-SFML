#include "Cursor.h"

Cursor::Cursor() :
	cursorTex_("Content/Textures/Cursor.png"),
	cursorSpr_(cursorTex_)
{
	cursorSpr_.setOrigin({ 250.f, 180.f });
	cursorSpr_.setScale({ 0.5f, 0.5f });
}

void Cursor::Update(const sf::RenderWindow& window) {

	sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
	sf::Vector2f mouse = window.mapPixelToCoords(mousePixel);

	cursorSpr_.setPosition(mouse);
}

void Cursor::Draw(sf::RenderWindow& window) {
	window.draw(cursorSpr_);
}
#pragma once

#include <SFML/Graphics.hpp>

class Cursor {

	private:
		sf::Texture cursorTex_;
		sf::Sprite cursorSpr_;
	public:
		Cursor();

		void Update(const sf::RenderWindow& window);
		void Draw(sf::RenderWindow& window);
};
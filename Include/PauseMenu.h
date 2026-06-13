#pragma once

#include <SFML/Graphics.hpp>

#include "GameConfig.h"
#include "GameState.h"

class PauseMenu {
	private:
		sf::Font font_;

		sf::Texture frameTex_;
		sf::RectangleShape frame_;

		sf::Text paused_;

		sf::Text resume_;
		sf::Text mainMenu_;
		sf::Text exit_;

	public:
		PauseMenu();

		GameState HandleClick(const sf::Vector2f& MousePos);
		void UpdateHover(const sf::Vector2f& MousePos);
		void Draw(sf::RenderWindow& window);
};
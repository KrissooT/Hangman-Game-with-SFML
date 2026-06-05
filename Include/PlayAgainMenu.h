#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class PlayAgainMenu {

	private:

		sf::Font font_;

		sf::Text wordWas_;
		sf::Text message_;
		sf::Text playAgainButton;
		sf::Text exitButton;

	public:

		PlayAgainMenu();

		GameState HandleClick(const sf::Vector2f& mousePos)const;

		void UpdateHover(const sf::Vector2f& mousePos);

		void Draw(sf::RenderWindow& window, GameState state, const std::string& mainWord);
};
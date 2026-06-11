#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "GameConfig.h"

class PlayAgainMenu {

	private:

		sf::Font font_;

		sf::Text wordWas_;
		sf::Text message_;
		sf::Text playAgainButton;
		sf::Text exitButton;

		sf::Texture WinBackgroundTex_;
		sf::Sprite WinBackgroundSpr_;

		sf::Texture LoseBackgroundTex_;
		sf::Sprite LoseBackgroundSpr_;

	public:

		PlayAgainMenu();

		GameState HandleClick(const sf::Vector2f& mousePos, GameState state)const;

		void UpdateHover(const sf::Vector2f& mousePos);

		void Draw(sf::RenderWindow& window, GameState state, const std::string& mainWord);
};
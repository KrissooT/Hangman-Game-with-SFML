#pragma once

#include <SFML/Graphics.hpp>

#include "Difficulty.h"
#include "GameState.h"

class DifficultyMenu {

	private:
		sf::Font font_;

		sf::Text ChooseDifficultyText;
		sf::Text EasyButton;
		sf::Text MediumButton;
		sf::Text HardButton;
		sf::Text ExtremeButton;
		sf::Text BackButton;

	public:

		DifficultyMenu();

		Difficulty HandleClick(const sf::Vector2f& MousePos);
		GameState Back(const sf::Vector2f& MousePos);
		void UpdateHover(const sf::Vector2f& MousePos);
		void Draw(sf::RenderWindow& window)const;
};
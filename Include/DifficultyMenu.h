#pragma once

#include <SFML/Graphics.hpp>

class DifficultyMenu {

	private:
		sf::Font font_;

		sf::Text ChooseDifficultyText;
		sf::Text EasyButton;
		sf::Text MediumButton;
		sf::Text HardButton;
		sf::Text ExtremeButton;

	public:

		DifficultyMenu();

		int HandleClick(const sf::Vector2f& mousePos);
		void Draw(sf::RenderWindow& window)const;
};
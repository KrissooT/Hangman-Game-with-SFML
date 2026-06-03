#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"

class MainMenu {
	private:

		sf::Font font_;

		sf::Text Title;
		sf::Text PlayButton;
		sf::Text OptionsButton;
		sf::Text ExitButton;

	public:

		MainMenu();

		GameState HandleClick(const sf::Vector2f& MousePos);
		void UpdateHover(const sf::Vector2f& MousePos);
		void Draw(sf::RenderWindow& window)const;
};
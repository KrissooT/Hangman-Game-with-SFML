#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
	private:

		sf::Font font_;

		sf::Text Title;
		sf::Text PlayButton;
		sf::Text OptionsButton;
		sf::Text ExitButton;

	public:

		MainMenu();

		int HandleClick(const sf::Vector2f& mousePos);
		void Draw(sf::RenderWindow& window)const;
};
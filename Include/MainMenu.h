#pragma once

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "GameConfig.h"

class MainMenu {
	private:

		sf::Font font_;

		sf::Text Title;
		sf::Text PlayButton;
		sf::Text OptionsButton;
		sf::Text ExitButton;

		sf::Texture backgroundTex_;
		sf::Sprite backgroundSpr_;
	public:

		MainMenu();

		GameState HandleClick(const sf::Vector2f& MousePos);
		void UpdateHover(const sf::Vector2f& MousePos);
		void Draw(sf::RenderWindow& window)const;
};
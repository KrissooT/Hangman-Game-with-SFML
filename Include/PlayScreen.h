#pragma once

#include <SFML/Graphics.hpp>

#include "Hangman.h"
#include "DrawHangman.h"
#include "GameConfig.h"

class PlayScreen {

	private:

		DrawHangman drawHangman_;
		Hangman hangman_;

		sf::Font font_;	

		sf::Text word_;
		sf::Text lives_;

		sf::Texture backgroundTex_;
		sf::Sprite backgroundSpr_;

	public:

		PlayScreen();

		void DrawKeyboard(sf::RenderWindow& window, const Hangman& hangman);
		void Draw(sf::RenderWindow& window,const Hangman& hangman);

};
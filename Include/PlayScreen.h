#pragma once

#include <SFML/Graphics.hpp>
#include "Hangman.h"
#include "DrawHangman.h"

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

		void Draw(sf::RenderWindow& window,const Hangman& hangman);

};
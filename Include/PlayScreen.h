#pragma once

#include <SFML/Graphics.hpp>
#include "Hangman.h"

class PlayScreen {

	private:

		Hangman hangman_;

		sf::Font font_;	

		sf::Text word_;
		sf::Text lives_;

	public:

		PlayScreen();

		void Draw(sf::RenderWindow& window,const Hangman& hangman);

};
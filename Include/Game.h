#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "DifficultyMenu.h"

class Game {

	private:
		sf::RenderWindow window_;
		Input input_;
		DifficultyMenu DifficultyMenu;

	public:
		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};
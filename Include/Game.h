#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "GameState.h"
#include "MainMenu.h"
#include "DifficultyMenu.h"
#include "Difficulty.h"

class Game {

	private:
		sf::RenderWindow window_;
		Input input_;
		GameState state_;
		MainMenu MainMenu;
		DifficultyMenu DifficultyMenu;
		Difficulty difficulty_;

	public:
		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};
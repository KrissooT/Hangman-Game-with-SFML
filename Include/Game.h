#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "MainMenu.h"
#include "DifficultyMenu.h"
#include "Hangman.h"
#include "PlayScreen.h"
#include "PlayAgainMenu.h"
#include "DrawHangman.h"
#include "Cursor.h"
#include "AudioManager.h"
#include "OptionsMenu.h"
#include "PauseMenu.h"

class Game {

	private:
		sf::RenderWindow window_;
		Input input_;
		GameState state_;
		MainMenu MainMenu;
		DifficultyMenu DifficultyMenu;
		Difficulty difficulty_;
		Hangman hangman_;
		PlayScreen PlayScreen;
		PlayAgainMenu PlayAgainMenu;
		DrawHangman drawHangman_;
		Cursor cursor_;
		AudioManager audioManager_;
		MusicState musicState_;
		OptionsMenu OptionsMenu;
		PauseMenu PauseMenu;

	public:
		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};
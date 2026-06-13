#include <SFML/GpuPreference.hpp>

#include "Game.h"
#include "GameConfig.h"
#include "iostream"

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle),
	state_(GameState::MainMenu),
	difficulty_(Difficulty::None)
{
	window_.setIcon(sf::Image("Content/Textures/IconTest.png"));
	window_.setMinimumSize(window_.getSize());
	window_.setMaximumSize(window_.getSize());

	window_.setKeyRepeatEnabled(false);
	window_.setMouseCursorVisible(false);

}

bool Game::IsRunning()const {
	return window_.isOpen();
}

void Game::ProcessEvents() {

	while (const auto event = window_.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window_.close();
		}

		if (const sf::Event::KeyPressed* key = event->getIf<sf::Event::KeyPressed>()) {
			if (key->code == sf::Keyboard::Key::Escape) {
				if (state_ == GameState::Playing) {
					state_ = GameState::Paused;
					audioManager_.PauseMusic();
				}
				else if (state_ == GameState::Paused) {
					state_ = GameState::Playing;
					audioManager_.ResumeMusic();
				}
			}
		}

		char letter;
		if (input_.HandleEvent(*event, letter)) {
			//TODO

			if (state_ == GameState::Playing) {
				hangman_.GuessLetter(letter);
				state_ = hangman_.CheckLives();
				audioManager_.PlayKeyPress();
			}
		}
	}
}

void Game::Update() {

	cursor_.Update(window_);

	input_.Update(window_);

	switch (state_) {
	case GameState::MainMenu:
		MainMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::DifficultyMenu:
		DifficultyMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::Options:
		OptionsMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::Paused:
		PauseMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::Won:
	case GameState::Lost:
		PlayAgainMenu.UpdateHover(input_.GetMousePos());
		break;
	}

	switch (state_) {
	case GameState::MainMenu:
	case GameState::DifficultyMenu:
	case GameState::Options:
		audioManager_.PlayMenuMusic();
		break;
	case GameState::Playing:
		audioManager_.PlayGameMusic();
		break;
	case GameState::Won:
		audioManager_.PlayWinMusic();
		break;
	case GameState::Lost:
		audioManager_.PlayLoseMusic();
		break;
	}

	if (input_.IsLeftMouseClicked()) {

		audioManager_.PlayMouseClick();

		if (state_ == GameState::MainMenu) {
			GameState nextState = MainMenu.HandleClick(input_.GetMousePos());
			if (nextState == GameState::Exit) {
				window_.close();
			}
			else {
				state_ = nextState;
			}
		}
		if (state_ == GameState::DifficultyMenu) {

			// GO BACK TO MAIN MENU
			GameState backState = DifficultyMenu.Back(input_.GetMousePos());
			if (backState == GameState::MainMenu) {
				state_ = backState;
				return;
			}

			//CHOOSE A DIFFICULTY
			difficulty_ = DifficultyMenu.HandleClick(input_.GetMousePos());
			if (difficulty_ != Difficulty::None) {
				state_ = GameState::Playing;
				hangman_.Run(difficulty_);
			}
		}

		if (state_ == GameState::Options) {
			OptionsActions action = OptionsMenu.HandleClick(input_.GetMousePos());

			switch (action) {
			case OptionsActions::MusicUp:
				gConfig.musicMute = false;
				audioManager_.SetMusicVolume(gConfig.musicVolume + 10);
				break;
			case OptionsActions::MusicDown:
				gConfig.musicMute = false;
				audioManager_.SetMusicVolume(gConfig.musicVolume - 10);
				break;
			case OptionsActions::SoundUp:
				gConfig.soundMute = false;
				audioManager_.SetSoundVolume(gConfig.soundVolume + 10);
				break;
			case OptionsActions::SoundDown:
				gConfig.soundMute = false;
				audioManager_.SetSoundVolume(gConfig.soundVolume - 10);
				break;
			case OptionsActions::MusicMute:
				audioManager_.ToggleMusicMute();
				break;
			case OptionsActions::SoundMute:
				audioManager_.ToggleSoundMute();
				break;
			case OptionsActions::None:
				break;
			}

			audioManager_.UpdateVolume();
			OptionsMenu.UpdateVolumeText();
			OptionsMenu.UpdateMuteBox();

			GameState backState = OptionsMenu.Back(input_.GetMousePos());
			if (backState == GameState::MainMenu) {
				state_ = backState;
				return;
			}

		}

		if (state_ == GameState::Won || state_ == GameState::Lost) {
			GameState nextState = PlayAgainMenu.HandleClick(input_.GetMousePos(), state_);
			if (nextState == GameState::Exit) {
				window_.close();
			}
			else {
				state_ = nextState;
			}
		}

		if (state_ == GameState::Paused) {
			GameState nextState = PauseMenu.HandleClick(input_.GetMousePos());
			if (nextState == GameState::Exit) {
				window_.close();
			}
			else if (nextState == GameState::Playing) {
				state_ = GameState::Playing;
				audioManager_.ResumeMusic();
			}
			else if (nextState == GameState::MainMenu) {
				state_ = GameState::MainMenu;
				audioManager_.PlayMenuMusic();
			}
		}
	}
}

void Game::Render() {
	window_.clear();

	switch (state_) {
	case GameState::MainMenu:
		MainMenu.Draw(window_);
		break;
	case GameState::DifficultyMenu:
		DifficultyMenu.Draw(window_);
		break;
	case GameState::Options:
		OptionsMenu.Draw(window_);
		break;
	case GameState::Playing:
		PlayScreen.Draw(window_, hangman_);
		drawHangman_.Draw(window_, hangman_.GetLives());
		break;
	case GameState::Paused:
		PlayScreen.Draw(window_, hangman_);
		drawHangman_.Draw(window_, hangman_.GetLives());
		PauseMenu.Draw(window_);
		break;
	case GameState::Won:
	case GameState::Lost:
		PlayAgainMenu.Draw(window_, state_, hangman_.GetSecretWord());
		break;
	}

	cursor_.Draw(window_);

	window_.display();
}
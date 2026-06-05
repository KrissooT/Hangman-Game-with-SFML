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
	window_.setIcon(sf::Image("Content/Textures/Icon.png"));
	window_.setMinimumSize(window_.getSize() / 2u);

	window_.setKeyRepeatEnabled(false);
}

bool Game::IsRunning()const {
	return window_.isOpen();
}

void Game::ProcessEvents() {

	while (const auto event = window_.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window_.close();
		}
		char letter;
		if (input_.HandleEvent(*event, letter)) {
			//TODO
			if (state_ == GameState::Playing) {
				hangman_.GuessLetter(letter);
				state_ = hangman_.CheckLives();
			}
		}
	}
}

void Game::Update() {
	input_.Update(window_);

	switch (state_) {
	case GameState::MainMenu:
		MainMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::DifficultyMenu:
		DifficultyMenu.UpdateHover(input_.GetMousePos());
		break;
	case GameState::Won:
	case GameState::Lost:
		PlayAgainMenu.UpdateHover(input_.GetMousePos());
		break;
	}

	if (input_.IsLeftMouseClicked()) {
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
			difficulty_ = DifficultyMenu.HandleClick(input_.GetMousePos());
			if (difficulty_ != Difficulty::None) {
				state_ = GameState::Playing;
				hangman_.Run(difficulty_);
			}
		}
		if (state_ == GameState::Won || state_ == GameState::Lost) {
			GameState nextState = PlayAgainMenu.HandleClick(input_.GetMousePos());
			if (nextState == GameState::Exit) {
				window_.close();
			}
			else {
				state_ = nextState;
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
		//Just for now TODO!
		window_.clear(sf::Color::Blue);
		break;
	case GameState::Playing:
		PlayScreen.Draw(window_, hangman_);
		break;
	case GameState::Won:
	case GameState::Lost:
		PlayAgainMenu.Draw(window_, state_, hangman_.GetSecretWord());
		break;
	}

	window_.display();
}
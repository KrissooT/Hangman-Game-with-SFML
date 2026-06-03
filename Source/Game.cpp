#include <SFML/GpuPreference.hpp>

#include "Game.h"
#include "GameConfig.h"

SFML_DEFINE_DISCRETE_GPU_PREFERENCE

Game::Game() :
	window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle),
	state_(GameState::MainMenu)
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
		}
	}
}

void Game::Update() {
	input_.Update(window_);
	MainMenu.UpdateHover(input_.GetMousePos());
	DifficultyMenu.UpdateHover(input_.GetMousePos());
	if (input_.IsLeftMouseClicked()) {
		int action = MainMenu.HandleClick(input_.GetMousePos());
		if (action == 0) {
			state_ = GameState::DifficultyMenu;
		}
		if (action == 2) {
			window_.close();
		}
	}
}

void Game::Render() {
	window_.clear();

	if (state_ == GameState::MainMenu) {
		MainMenu.Draw(window_);
	}
	if (state_ == GameState::DifficultyMenu) {
		DifficultyMenu.Draw(window_);
	}
	window_.display();
}
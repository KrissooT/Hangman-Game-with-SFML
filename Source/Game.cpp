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
	//TODO
}

void Game::Render() {
	window_.clear();
	MainMenu.Draw(window_);
	//DifficultyMenu.Draw(window_);
	window_.display();
}
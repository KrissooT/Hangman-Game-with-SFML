#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"

class Game {

	private:
		sf::RenderWindow window_;
		Input input_;

	public:
		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};
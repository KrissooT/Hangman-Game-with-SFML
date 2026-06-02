#pragma once

#include <SFML/Graphics.hpp>

class Game {

	private:
		sf::RenderWindow window_;
		sf::Image icon;

	public:
		Game();

		bool IsRunning()const;

		void ProcessEvents();
		void Update();
		void Render();
};
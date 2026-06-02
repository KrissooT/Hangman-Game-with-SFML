#pragma once

#include <SFML/Graphics.hpp>

class Input {
	public:
		bool HandleEvent(const sf::Event& event, char& letter);
};
#pragma once

#include <SFML/Graphics.hpp>

struct Input {
	public:
		bool HandleEvent(const sf::Event& event, char& letter);
};
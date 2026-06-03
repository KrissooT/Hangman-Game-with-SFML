#pragma once

#include <SFML/Graphics.hpp>

struct Input {
	public:
		bool HandleEvent(const sf::Event& event, char& letter);

		void Update(const sf::RenderWindow& window);
		bool IsLeftMouseClicked()const;
		sf::Vector2f GetMousePos()const;

	private:
		sf::Vector2f MousePos;
		bool leftPressed_ = false;
		bool leftClicked_ = false;
};
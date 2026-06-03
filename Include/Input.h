#pragma once

#include <SFML/Graphics.hpp>

struct Input {
	public:
		//Keyboard
		bool HandleEvent(const sf::Event& event, char& letter);

		//Mouse
		void Update(const sf::RenderWindow& window);
		bool IsLeftMouseClicked()const;
		sf::Vector2f GetMousePos()const;

	private:
		sf::Vector2f MousePos;
		bool leftPressed_ = false;
		bool leftClicked_ = false;
};
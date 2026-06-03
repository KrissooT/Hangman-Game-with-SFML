#include "Input.h"

#include <iostream>

bool Input::HandleEvent(const sf::Event& event, char& letter){

	if (auto * keyPressed = event.getIf<sf::Event::KeyPressed>()) {
		sf::Keyboard::Key key = keyPressed->code;

		switch (key) {
		case sf::Keyboard::Key::A: letter = 'A'; return true;
		case sf::Keyboard::Key::B: letter = 'B'; return true;
		case sf::Keyboard::Key::C: letter = 'C'; return true;
		case sf::Keyboard::Key::D: letter = 'D'; return true;
		case sf::Keyboard::Key::E: letter = 'E'; return true;
		case sf::Keyboard::Key::F: letter = 'F'; return true;
		case sf::Keyboard::Key::G: letter = 'G'; return true;
		case sf::Keyboard::Key::H: letter = 'H'; return true;
		case sf::Keyboard::Key::I: letter = 'I'; return true;
		case sf::Keyboard::Key::J: letter = 'J'; return true;
		case sf::Keyboard::Key::K: letter = 'K'; return true;
		case sf::Keyboard::Key::L: letter = 'L'; return true;
		case sf::Keyboard::Key::M: letter = 'M'; return true;
		case sf::Keyboard::Key::N: letter = 'N'; return true;
		case sf::Keyboard::Key::O: letter = 'O'; return true;
		case sf::Keyboard::Key::P: letter = 'P'; return true;
		case sf::Keyboard::Key::Q: letter = 'Q'; return true;
		case sf::Keyboard::Key::R: letter = 'R'; return true;
		case sf::Keyboard::Key::S: letter = 'S'; return true;
		case sf::Keyboard::Key::T: letter = 'T'; return true;
		case sf::Keyboard::Key::U: letter = 'U'; return true;
		case sf::Keyboard::Key::V: letter = 'V'; return true;
		case sf::Keyboard::Key::W: letter = 'W'; return true;
		case sf::Keyboard::Key::X: letter = 'X'; return true;
		case sf::Keyboard::Key::Y: letter = 'Y'; return true;
		case sf::Keyboard::Key::Z: letter = 'Z'; return true;
		default:break;
		}
	}
	return false;
}

void Input::Update(const sf::RenderWindow& window) {
	sf::Vector2i pixels = sf::Mouse::getPosition(window);
	MousePos = window.mapPixelToCoords(pixels);


	bool currentPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

	leftClicked_ = (currentPressed && !leftPressed_);
	leftPressed_ = currentPressed;
}

sf::Vector2f Input::GetMousePos()const{
	return MousePos;
}

bool Input::IsLeftMouseClicked()const {
	return leftClicked_;
}
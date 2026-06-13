#include "PauseMenu.h"

PauseMenu::PauseMenu() :
	font_("Content/Fonts/PlayAgainFont.ttf"),
	paused_(font_),
	resume_(font_),
	mainMenu_(font_),
	exit_(font_)
{

	frameTex_.loadFromFile("Content/Assets/Backgrounds/PauseMenuBackground.png");

	//Paused
	paused_.setString("Paused");
	paused_.setCharacterSize(40);
	paused_.setOutlineThickness(3);

	paused_.setOrigin(paused_.getGlobalBounds().getCenter());
	paused_.setPosition({ gConfig.windowSize.x / 2, 235 });

	//Resume Button
	resume_.setString("Resume");
	resume_.setCharacterSize(35);
	resume_.setOutlineThickness(3);

	resume_.setOrigin(resume_.getGlobalBounds().getCenter());
	resume_.setPosition({gConfig.windowSize.x / 2, 347});

	//Main Menu Button
	mainMenu_.setString("Main Menu");
	mainMenu_.setCharacterSize(35);
	mainMenu_.setOutlineThickness(3);

	mainMenu_.setOrigin(mainMenu_.getGlobalBounds().getCenter());
	mainMenu_.setPosition({ gConfig.windowSize.x / 2, 425 });

	//Exit
	exit_.setString("Quit Game");
	exit_.setCharacterSize(35);
	exit_.setOutlineThickness(3);

	exit_.setOrigin(exit_.getGlobalBounds().getCenter());
	exit_.setPosition({ gConfig.windowSize.x / 2, 510 });

	//Frame
	frame_.setTexture(&frameTex_);
	frame_.setSize({300,450});

	frame_.setOrigin(frame_.getGlobalBounds().getCenter());
	frame_.setPosition({ gConfig.windowSize.x / 2, 400 });
}

GameState PauseMenu::HandleClick(const sf::Vector2f& MousePos) {
	if (resume_.getGlobalBounds().contains(MousePos)) {
		return GameState::Playing;
	}
	if (mainMenu_.getGlobalBounds().contains(MousePos)) {
		return GameState::MainMenu;
	}
	if (exit_.getGlobalBounds().contains(MousePos)) {
		return GameState::Exit;
	}
	return GameState::Paused;
}

void PauseMenu::UpdateHover(const sf::Vector2f& MousePos) {
	//Resume Button
	if (resume_.getGlobalBounds().contains(MousePos)) {
		resume_.setFillColor(sf::Color::Red);
		resume_.setStyle(sf::Text::Style::Bold);
	}
	else {
		resume_.setFillColor(sf::Color::Green);
		resume_.setStyle(sf::Text::Style::Regular);
	}

	//Main Menu Button
	if (mainMenu_.getGlobalBounds().contains(MousePos)) {
		mainMenu_.setFillColor(sf::Color::Red);
		mainMenu_.setStyle(sf::Text::Style::Bold);
	}
	else {
		mainMenu_.setFillColor(sf::Color::Green);
		mainMenu_.setStyle(sf::Text::Style::Regular);
	}

	//Exit Button
	if (exit_.getGlobalBounds().contains(MousePos)) {
		exit_.setFillColor(sf::Color::Red);
		exit_.setStyle(sf::Text::Style::Bold);
	}
	else {
		exit_.setFillColor(sf::Color::Green);
		exit_.setStyle(sf::Text::Style::Regular);
	}
}

void PauseMenu::Draw(sf::RenderWindow& window) {
	window.draw(frame_);
	window.draw(paused_);
	window.draw(resume_);
	window.draw(mainMenu_);
	window.draw(exit_);
}
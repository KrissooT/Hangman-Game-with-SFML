#include "MainMenu.h"

MainMenu::MainMenu():
	backgroundTex_("Content/Assets/Backgrounds/MainMenuBackground.png"),
	font_("Content/Fonts/MenuFont.ttf"),
	backgroundSpr_(backgroundTex_),
	Title(font_),
	PlayButton(font_),
	OptionsButton(font_),
	ExitButton(font_)
{
	//Background
	auto backgroundSize = backgroundTex_.getSize();
	float backgroundX = gConfig.windowSize.x / backgroundSize.x;
	float backgroundY = gConfig.windowSize.y / backgroundSize.y;
	backgroundSpr_.setScale({ backgroundX, backgroundY});

	//Title
	Title.setString("Hangman");
	Title.setCharacterSize(100);
	Title.setFillColor(sf::Color::Red);

	Title.setOrigin(Title.getGlobalBounds().getCenter());
	Title.setPosition({ gConfig.windowSize.x / 2, 60 });

	//PlayButton
	PlayButton.setString("Play");
	PlayButton.setCharacterSize(60);
	PlayButton.setFillColor(sf::Color::Green);

	PlayButton.setOrigin(PlayButton.getGlobalBounds().getCenter());
	PlayButton.setPosition({ gConfig.windowSize.x / 2, 250 });

	//OptionsButton
	OptionsButton.setString("Options");
	OptionsButton.setCharacterSize(60);
	OptionsButton.setFillColor(sf::Color::Green);

	OptionsButton.setOrigin(OptionsButton.getGlobalBounds().getCenter());
	OptionsButton.setPosition({ gConfig.windowSize.x / 2, 400});

	//ExitButton
	ExitButton.setString("Exit");
	ExitButton.setCharacterSize(60);
	ExitButton.setFillColor(sf::Color::Green);

	ExitButton.setOrigin(ExitButton.getGlobalBounds().getCenter());
	ExitButton.setPosition({ gConfig.windowSize.x / 2,550 });
}

GameState MainMenu::HandleClick(const sf::Vector2f& MousePos)
{
	if (PlayButton.getGlobalBounds().contains(MousePos)) {
		return GameState::DifficultyMenu;
	}

	if (OptionsButton.getGlobalBounds().contains(MousePos)) {
		return GameState::Options;
	}

	if (ExitButton.getGlobalBounds().contains(MousePos)) {
		return GameState::Exit;
	}
}

void MainMenu::UpdateHover(const sf::Vector2f& MousePos) {
	
	//PlayButton
	if (PlayButton.getGlobalBounds().contains(MousePos)) {
		PlayButton.setFillColor(sf::Color::Red);
		PlayButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		PlayButton.setFillColor(sf::Color::Green);
		PlayButton.setStyle(sf::Text::Style::Regular);
	}

	//OptionsButton
	if (OptionsButton.getGlobalBounds().contains(MousePos)) {
		OptionsButton.setFillColor(sf::Color::Red);
		OptionsButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		OptionsButton.setFillColor(sf::Color::Green);
		OptionsButton.setStyle(sf::Text::Style::Regular);
	}

	//ExitButton
	if (ExitButton.getGlobalBounds().contains(MousePos)) {
		ExitButton.setFillColor(sf::Color::Red);
		ExitButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		ExitButton.setFillColor(sf::Color::Green);
		ExitButton.setStyle(sf::Text::Style::Regular);
	}
}

void MainMenu::Draw(sf::RenderWindow& window)const {
	window.draw(backgroundSpr_);
	window.draw(Title);
	window.draw(PlayButton);
	window.draw(OptionsButton);
	window.draw(ExitButton);
}
#include "MainMenu.h"

MainMenu::MainMenu():
	font_("Content/Fonts/Font.ttf"),
	Title(font_),
	PlayButton(font_),
	OptionsButton(font_),
	ExitButton(font_)
{
	//Title
	Title.setString("Hangman");
	Title.setCharacterSize(70);
	Title.setFillColor(sf::Color::Red);

	Title.setOrigin(Title.getGlobalBounds().getCenter());
	Title.setPosition({ 400, 50 });

	//PlayButton
	PlayButton.setString("Play");
	PlayButton.setCharacterSize(50);
	PlayButton.setFillColor(sf::Color::Green);

	PlayButton.setOrigin(PlayButton.getGlobalBounds().getCenter());
	PlayButton.setPosition({ 400,250 });

	//OptionsButton
	OptionsButton.setString("Options");
	OptionsButton.setCharacterSize(50);
	OptionsButton.setFillColor(sf::Color::Green);

	OptionsButton.setOrigin(OptionsButton.getGlobalBounds().getCenter());
	OptionsButton.setPosition({400,400});

	//ExitButton
	ExitButton.setString("Exit");
	ExitButton.setCharacterSize(50);
	ExitButton.setFillColor(sf::Color::Green);

	ExitButton.setOrigin(ExitButton.getGlobalBounds().getCenter());
	ExitButton.setPosition({ 400,550 });
}

int MainMenu::HandleClick(const sf::Vector2f& MousePos)
{
	if (PlayButton.getGlobalBounds().contains(MousePos))
		return 0;

	if (OptionsButton.getGlobalBounds().contains(MousePos))
		return 1;

	if (ExitButton.getGlobalBounds().contains(MousePos))
		return 2;

	return -1;
}

void MainMenu::UpdateHover(const sf::Vector2f& MousePos) {
	
	//PlayButton
	if (PlayButton.getGlobalBounds().contains(MousePos)) {
		PlayButton.setFillColor(sf::Color::Red);
		PlayButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		PlayButton.setFillColor(sf::Color::Green);
		PlayButton.setStyle(sf::Text::Style::Regular);
	}

	//OptionsButton
	if (OptionsButton.getGlobalBounds().contains(MousePos)) {
		OptionsButton.setFillColor(sf::Color::Red);
		OptionsButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		OptionsButton.setFillColor(sf::Color::Green);
		OptionsButton.setStyle(sf::Text::Style::Regular);
	}

	//ExitButton
	if (ExitButton.getGlobalBounds().contains(MousePos)) {
		ExitButton.setFillColor(sf::Color::Red);
		ExitButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		ExitButton.setFillColor(sf::Color::Green);
		ExitButton.setStyle(sf::Text::Style::Regular);
	}
}

void MainMenu::Draw(sf::RenderWindow& window)const {
	window.draw(Title);
	window.draw(PlayButton);
	window.draw(OptionsButton);
	window.draw(ExitButton);
}
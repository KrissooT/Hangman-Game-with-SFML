#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu() :
	font_("Content/Fonts/Font.ttf"),
	ChooseDifficultyText(font_),
	EasyButton(font_),
	MediumButton(font_),
	HardButton(font_),
	ExtremeButton(font_),
	BackButton(font_)
{
	//Choose a Difficulty Text
	ChooseDifficultyText.setString("Choose your difficulty:");
	ChooseDifficultyText.setCharacterSize(50);
	ChooseDifficultyText.setFillColor(sf::Color::Red);

	ChooseDifficultyText.setOrigin(ChooseDifficultyText.getGlobalBounds().getCenter());
	ChooseDifficultyText.setPosition({ 400,50 });


	//Easy Button
	EasyButton.setString("Easy");
	EasyButton.setCharacterSize(50);
	EasyButton.setFillColor(sf::Color::Green);

	EasyButton.setOrigin(EasyButton.getGlobalBounds().getCenter());
	EasyButton.setPosition({ 400,170 });

	//MediumButton
	MediumButton.setString("Medium");
	MediumButton.setCharacterSize(50);
	MediumButton.setFillColor(sf::Color::Green);

	MediumButton.setOrigin(MediumButton.getGlobalBounds().getCenter());
	MediumButton.setPosition({ 400,320 });

	//Hard Button
	HardButton.setString("Hard");
	HardButton.setCharacterSize(50);
	HardButton.setFillColor(sf::Color::Green);

	HardButton.setOrigin(HardButton.getGlobalBounds().getCenter());
	HardButton.setPosition({ 400,470 });

	//Extreme Button
	ExtremeButton.setString("Extreme");
	ExtremeButton.setCharacterSize(50);
	ExtremeButton.setFillColor(sf::Color::Green);
	
	ExtremeButton.setOrigin(ExtremeButton.getGlobalBounds().getCenter());
	ExtremeButton.setPosition({400,620});

	//Back Button
	BackButton.setString("Back");
	BackButton.setCharacterSize(50);
	BackButton.setFillColor(sf::Color::Green);

	BackButton.setOrigin(BackButton.getGlobalBounds().getCenter());
	BackButton.setPosition({ 100,700 });
}

Difficulty DifficultyMenu::HandleClick(const sf::Vector2f& MousePos)
{
	if (EasyButton.getGlobalBounds().contains(MousePos)) {
		return Difficulty::Easy;
	}

	if (MediumButton.getGlobalBounds().contains(MousePos)) {
		return Difficulty::Medium;
	}

	if (HardButton.getGlobalBounds().contains(MousePos)) {
		return Difficulty::Hard;
	}

	if (ExtremeButton.getGlobalBounds().contains(MousePos)) {
		return Difficulty::Extreme;
	}

}

GameState DifficultyMenu::Back(const sf::Vector2f& MousePos) {
	if (BackButton.getGlobalBounds().contains(MousePos)) {
		return GameState::MainMenu;
	}
	return GameState::DifficultyMenu;
}

void DifficultyMenu::UpdateHover(const sf::Vector2f& MousePos) {
	
	//Easy Button
	if (EasyButton.getGlobalBounds().contains(MousePos)) {
		EasyButton.setFillColor(sf::Color::Red);
		EasyButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		EasyButton.setFillColor(sf::Color::Green);
		EasyButton.setStyle(sf::Text::Style::Regular);
	}

	//Medium Button
	if (MediumButton.getGlobalBounds().contains(MousePos)) {
		MediumButton.setFillColor(sf::Color::Red);
		MediumButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		MediumButton.setFillColor(sf::Color::Green);
		MediumButton.setStyle(sf::Text::Style::Regular);
	}

	//Hard Button
	if (HardButton.getGlobalBounds().contains(MousePos)) {
		HardButton.setFillColor(sf::Color::Red);
		HardButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		HardButton.setFillColor(sf::Color::Green);
		HardButton.setStyle(sf::Text::Style::Regular);
	}

	//Extreme Button
	if (ExtremeButton.getGlobalBounds().contains(MousePos)) {
		ExtremeButton.setFillColor(sf::Color::Red);
		ExtremeButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		ExtremeButton.setFillColor(sf::Color::Green);
		ExtremeButton.setStyle(sf::Text::Style::Regular);
	}

	//Back Button
	if (BackButton.getGlobalBounds().contains(MousePos)) {
		BackButton.setFillColor(sf::Color::Red);
		BackButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		BackButton.setFillColor(sf::Color::Green);
		BackButton.setStyle(sf::Text::Style::Regular);
	}
}

void DifficultyMenu::Draw(sf::RenderWindow& window)const {
	window.draw(ChooseDifficultyText);
	window.draw(EasyButton);
	window.draw(MediumButton);
	window.draw(HardButton);
	window.draw(ExtremeButton);
	window.draw(BackButton);
}
#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu() :
	font_("Content/Fonts/Font.ttf"),
	ChooseDifficultyText(font_),
	EasyButton(font_),
	MediumButton(font_),
	HardButton(font_),
	ExtremeButton(font_)
{
	//ChooseDifficultyText
	ChooseDifficultyText.setString("Choose your difficulty:");
	ChooseDifficultyText.setCharacterSize(50);
	ChooseDifficultyText.setFillColor(sf::Color::Red);

	ChooseDifficultyText.setOrigin(ChooseDifficultyText.getGlobalBounds().getCenter());
	ChooseDifficultyText.setPosition({ 400,50 });


	//EasyButton
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

	//HardButton
	HardButton.setString("Hard");
	HardButton.setCharacterSize(50);
	HardButton.setFillColor(sf::Color::Green);

	HardButton.setOrigin(HardButton.getGlobalBounds().getCenter());
	HardButton.setPosition({ 400,470 });

	//ExtremeButton
	ExtremeButton.setString("Extreme");
	ExtremeButton.setCharacterSize(50);
	ExtremeButton.setFillColor(sf::Color::Green);
	
	ExtremeButton.setOrigin(ExtremeButton.getGlobalBounds().getCenter());
	ExtremeButton.setPosition({400,620});
}

Difficulty DifficultyMenu::HandleClick(const sf::Vector2f& mousePos)
{
	if (EasyButton.getGlobalBounds().contains(mousePos)) {
		return Difficulty::Easy;
	}

	if (MediumButton.getGlobalBounds().contains(mousePos)) {
		return Difficulty::Medium;
	}

	if (HardButton.getGlobalBounds().contains(mousePos)) {
		return Difficulty::Hard;
	}

	if (ExtremeButton.getGlobalBounds().contains(mousePos)) {
		return Difficulty::Extreme;
	}
}

void DifficultyMenu::UpdateHover(const sf::Vector2f& MousePos) {
	
	//EasyButton
	if (EasyButton.getGlobalBounds().contains(MousePos)) {
		EasyButton.setFillColor(sf::Color::Red);
		EasyButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		EasyButton.setFillColor(sf::Color::Green);
		EasyButton.setStyle(sf::Text::Style::Regular);
	}

	//MediumButton
	if (MediumButton.getGlobalBounds().contains(MousePos)) {
		MediumButton.setFillColor(sf::Color::Red);
		MediumButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		MediumButton.setFillColor(sf::Color::Green);
		MediumButton.setStyle(sf::Text::Style::Regular);
	}

	//HardButton
	if (HardButton.getGlobalBounds().contains(MousePos)) {
		HardButton.setFillColor(sf::Color::Red);
		HardButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		HardButton.setFillColor(sf::Color::Green);
		HardButton.setStyle(sf::Text::Style::Regular);
	}

	//ExtremeButton
	if (ExtremeButton.getGlobalBounds().contains(MousePos)) {
		ExtremeButton.setFillColor(sf::Color::Red);
		ExtremeButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		ExtremeButton.setFillColor(sf::Color::Green);
		ExtremeButton.setStyle(sf::Text::Style::Regular);
	}
}

void DifficultyMenu::Draw(sf::RenderWindow& window)const {
	window.draw(ChooseDifficultyText);
	window.draw(EasyButton);
	window.draw(MediumButton);
	window.draw(HardButton);
	window.draw(ExtremeButton);
}
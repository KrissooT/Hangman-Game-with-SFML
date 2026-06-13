#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu() :
	backgroundTex_("Content/Assets/Backgrounds/DifficultyMenuBackground.png"),
	backgroundSpr_(backgroundTex_),
	font_("Content/Fonts/MenuFont.ttf"),
	ChooseDifficultyText(font_),
	EasyButton(font_),
	MediumButton(font_),
	HardButton(font_),
	ExtremeButton(font_),
	BackButton(font_)
{
	//Background
	auto backgroundSize = backgroundTex_.getSize();
	float backgroundX = gConfig.windowSize.x / backgroundSize.x;
	float backgroundY = gConfig.windowSize.y / backgroundSize.y;
	backgroundSpr_.setScale({ backgroundX, backgroundY });

	//Choose a Difficulty Text
	ChooseDifficultyText.setString("Difficulty:");
	ChooseDifficultyText.setCharacterSize(40);
	ChooseDifficultyText.setFillColor(sf::Color::Red);

	ChooseDifficultyText.setOrigin(ChooseDifficultyText.getGlobalBounds().getCenter());
	ChooseDifficultyText.setPosition({ gConfig.windowSize.x / 2, 235 });


	//Easy Button
	EasyButton.setString("Easy");
	EasyButton.setCharacterSize(50);
	EasyButton.setFillColor(sf::Color::Green);

	EasyButton.setOrigin(EasyButton.getGlobalBounds().getCenter());
	EasyButton.setPosition({ gConfig.windowSize.x / 2, 300 });

	//MediumButton
	MediumButton.setString("Medium");
	MediumButton.setCharacterSize(50);
	MediumButton.setFillColor(sf::Color::Green);

	MediumButton.setOrigin(MediumButton.getGlobalBounds().getCenter());
	MediumButton.setPosition({ gConfig.windowSize.x / 2, 385 });

	//Hard Button
	HardButton.setString("Hard");
	HardButton.setCharacterSize(50);
	HardButton.setFillColor(sf::Color::Green);

	HardButton.setOrigin(HardButton.getGlobalBounds().getCenter());
	HardButton.setPosition({ gConfig.windowSize.x / 2, 465 });

	//Extreme Button
	ExtremeButton.setString("Extreme");
	ExtremeButton.setCharacterSize(50);
	ExtremeButton.setFillColor(sf::Color::Green);
	
	ExtremeButton.setOrigin(ExtremeButton.getGlobalBounds().getCenter());
	ExtremeButton.setPosition({ gConfig.windowSize.x / 2, 545});

	//Back Button
	float BackButtonX = (gConfig.windowSize.x - gConfig.windowSize.x) + 100;
	float BackButtonY = gConfig.windowSize.y - 100;

	BackButton.setString("Back");
	BackButton.setCharacterSize(50);
	BackButton.setFillColor(sf::Color::Green);

	BackButton.setOrigin(BackButton.getGlobalBounds().getCenter());
	BackButton.setPosition({ BackButtonX, BackButtonY });
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
		EasyButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		EasyButton.setFillColor(sf::Color::Green);
		EasyButton.setStyle(sf::Text::Style::Regular);
	}

	//Medium Button
	if (MediumButton.getGlobalBounds().contains(MousePos)) {
		MediumButton.setFillColor(sf::Color::Red);
		MediumButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		MediumButton.setFillColor(sf::Color::Green);
		MediumButton.setStyle(sf::Text::Style::Regular);
	}

	//Hard Button
	if (HardButton.getGlobalBounds().contains(MousePos)) {
		HardButton.setFillColor(sf::Color::Red);
		HardButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		HardButton.setFillColor(sf::Color::Green);
		HardButton.setStyle(sf::Text::Style::Regular);
	}

	//Extreme Button
	if (ExtremeButton.getGlobalBounds().contains(MousePos)) {
		ExtremeButton.setFillColor(sf::Color::Red);
		ExtremeButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		ExtremeButton.setFillColor(sf::Color::Green);
		ExtremeButton.setStyle(sf::Text::Style::Regular);
	}

	//Back Button
	if (BackButton.getGlobalBounds().contains(MousePos)) {
		BackButton.setFillColor(sf::Color::Red);
		BackButton.setStyle(sf::Text::Style::Bold);
	}
	else {
		BackButton.setFillColor(sf::Color::Green);
		BackButton.setStyle(sf::Text::Style::Regular);
	}
}

void DifficultyMenu::Draw(sf::RenderWindow& window)const {
	window.draw(backgroundSpr_);
	window.draw(ChooseDifficultyText);
	window.draw(EasyButton);
	window.draw(MediumButton);
	window.draw(HardButton);
	window.draw(ExtremeButton);
	window.draw(BackButton);
}
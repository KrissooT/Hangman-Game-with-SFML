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
	ChooseDifficultyText.setPosition({ 400,100 });


	//EasyButton
	EasyButton.setString("Easy");
	EasyButton.setCharacterSize(50);
	EasyButton.setFillColor(sf::Color::Green);

	EasyButton.setOrigin(EasyButton.getGlobalBounds().getCenter());
	EasyButton.setPosition({ 400,300 });

	//MediumButton
	MediumButton.setString("Medium");
	MediumButton.setCharacterSize(50);
	MediumButton.setFillColor(sf::Color::Green);

	MediumButton.setOrigin(MediumButton.getGlobalBounds().getCenter());
	MediumButton.setPosition({ 400,400 });

	//HardButton
	HardButton.setString("Hard");
	HardButton.setCharacterSize(50);
	HardButton.setFillColor(sf::Color::Green);

	HardButton.setOrigin(HardButton.getGlobalBounds().getCenter());
	HardButton.setPosition({ 400,500 });

	//ExtremeButton
	ExtremeButton.setString("Extreme");
	ExtremeButton.setCharacterSize(50);
	ExtremeButton.setFillColor(sf::Color::Green);
	
	ExtremeButton.setOrigin(ExtremeButton.getGlobalBounds().getCenter());
	ExtremeButton.setPosition({400,600});
}

int DifficultyMenu::HandleClick(const sf::Vector2f& mousePos)
{
	if (EasyButton.getGlobalBounds().contains(mousePos))
		return 0;

	if (MediumButton.getGlobalBounds().contains(mousePos))
		return 1;

	if (HardButton.getGlobalBounds().contains(mousePos))
		return 2;

	if (ExtremeButton.getGlobalBounds().contains(mousePos))
		return 3;

	return -1;
}

void DifficultyMenu::Draw(sf::RenderWindow& window)const {
	window.draw(ChooseDifficultyText);
	window.draw(EasyButton);
	window.draw(MediumButton);
	window.draw(HardButton);
	window.draw(ExtremeButton);
}
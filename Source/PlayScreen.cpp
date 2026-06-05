#include "PlayScreen.h"

PlayScreen::PlayScreen() :
	font_("Content/Fonts/Font.ttf"),
	word_(font_),
	lives_(font_)
{
	//Word
	word_.setCharacterSize(50);

	//Lives
	lives_.setString("Lives: " + std::to_string(hangman_.GetLives()));
	lives_.setCharacterSize(50);

	lives_.setOrigin(lives_.getGlobalBounds().getCenter());
	lives_.setPosition({ 100, 50 });
}

void PlayScreen::Draw(sf::RenderWindow& window,const Hangman& hangman){
	word_.setString(hangman.GetMaskedWord());

	auto bounds = word_.getLocalBounds();
	word_.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });
	word_.setPosition({ 400, 400 });

	window.draw(word_);
	window.draw(lives_);
}
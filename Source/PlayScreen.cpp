#include "PlayScreen.h"

PlayScreen::PlayScreen() :
	font_("Content/Fonts/Font.ttf"),
	word_(font_),
	lives_(font_),
	backgroundTex_("Content/Textures/PlayScreenBackground.png"),
	backgroundSpr_(backgroundTex_)
{
	//Word
	word_.setCharacterSize(50);

	//Lives
	lives_.setCharacterSize(50);

	lives_.setOrigin(lives_.getGlobalBounds().getCenter());
	lives_.setPosition({ 5, 5 });

	auto backgroundSize = backgroundTex_.getSize();
	backgroundSpr_.setScale({ 1000.f / backgroundSize.x, 800.f / backgroundSize.y });

}

void PlayScreen::Draw(sf::RenderWindow& window,const Hangman& hangman){

	drawHangman_.Draw(window, hangman.GetLives());

	std::string spaced;
	for (char c : hangman.GetMaskedWord()) {
		spaced += c;
		spaced += ' ';
	}
	word_.setString(spaced);

	auto bounds = word_.getLocalBounds();
	word_.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });
	word_.setPosition({ 400, 400 });

	lives_.setString("Lives: " + std::to_string(hangman.GetLives()));

	window.draw(backgroundSpr_);
	window.draw(word_);
	window.draw(lives_);
}
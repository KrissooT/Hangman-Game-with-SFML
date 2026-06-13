#include "PlayScreen.h"

PlayScreen::PlayScreen() :
	font_("Content/Fonts/KeyboardAndWordFont.ttf"),
	word_(font_),
	lives_(font_),
	backgroundTex_("Content/Assets/Backgrounds/PlayscreenBackground.png"),
	backgroundSpr_(backgroundTex_),
	keyboard_(font_)
{
	//Lives
	lives_.setCharacterSize(50);

	lives_.setOrigin(lives_.getGlobalBounds().getCenter());
	lives_.setPosition({ 5, 5 });

	auto backgroundSize = backgroundTex_.getSize();
	backgroundSpr_.setScale({ 1000.f / backgroundSize.x, 800.f / backgroundSize.y });

}

void PlayScreen::DrawKeyboard(sf::RenderWindow& window, const Hangman& hangman) {
	for (char c = 'A'; c <= 'Z'; ++c) {

		keyboard_.setString(std::string(1, c));
		keyboard_.setCharacterSize(40);
		keyboard_.setOutlineThickness(5);

		if (hangman.GetGuessedLetters().contains(c)) {
			keyboard_.setFillColor(sf::Color::Red);
		}
		else {
			keyboard_.setFillColor(sf::Color::White);
		}

		int index = c - 'A';
		int cols = 13;

		int row = index / cols;
		int col = index % cols;

		keyboard_.setPosition({
			100.f + col * 65.f,
			650.f + row * 65.f
			});

		window.draw(keyboard_);
	}
}

void PlayScreen::Draw(sf::RenderWindow& window,const Hangman& hangman){

	window.draw(backgroundSpr_);
	drawHangman_.Draw(window, hangman.GetLives());

	std::string spaced;
	for (char c : hangman.GetMaskedWord()) {
		spaced += c;
		spaced += ' ';
	}

	//Word
	word_.setCharacterSize(50);
	word_.setString(spaced);
	word_.setOutlineThickness(5);

	auto bounds = word_.getLocalBounds();
	word_.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });
	word_.setPosition({ gConfig.windowSize.x / 2, 70 });

	lives_.setString("Lives: " + std::to_string(hangman.GetLives()));

	window.draw(word_);
	window.draw(lives_);

	DrawKeyboard(window, hangman);

}
#include "PlayAgainMenu.h"

PlayAgainMenu::PlayAgainMenu() :
	WinBackgroundTex_("Content/Assets/Backgrounds/WinScreenBackground.png"),
	WinBackgroundSpr_(WinBackgroundTex_),
	LoseBackgroundTex_("Content/Assets/Backgrounds/LoseScreenBackground.png"),
	LoseBackgroundSpr_(LoseBackgroundTex_),
	font_("Content/Fonts/PlayAgainFont.ttf"),
	playAgainButton(font_),
	message_(font_),
	wordWas_(font_),
	exitButton(font_)
{

	//Background
	auto backgroundSize = WinBackgroundTex_.getSize();
	float backgroundX = gConfig.windowSize.x / backgroundSize.x;
	float backgroundY = gConfig.windowSize.y / backgroundSize.y;
	WinBackgroundSpr_.setScale({ backgroundX, backgroundY });
	LoseBackgroundSpr_.setScale({ backgroundX, backgroundY });

	//Play Again Button
	playAgainButton.setString("Play again ?");
	playAgainButton.setCharacterSize(50);
	playAgainButton.setFillColor(sf::Color::Green);

	playAgainButton.setOrigin(playAgainButton.getGlobalBounds().getCenter());

	//Exit Button
	exitButton.setString("Exit");
	exitButton.setCharacterSize(50);
	exitButton.setFillColor(sf::Color::Green);

	exitButton.setOrigin(exitButton.getGlobalBounds().getCenter());
}

GameState PlayAgainMenu::HandleClick(const sf::Vector2f& mousePos, GameState state)const {

	if (playAgainButton.getGlobalBounds().contains(mousePos)) {
		return GameState::DifficultyMenu;
	}

	if (exitButton.getGlobalBounds().contains(mousePos)) {
		return GameState::Exit;
	}
	return state;
}

void PlayAgainMenu::UpdateHover(const sf::Vector2f& mousePos) {

	//Play Again Button
	if (playAgainButton.getGlobalBounds().contains(mousePos)) {
		playAgainButton.setFillColor(sf::Color::Red);
		playAgainButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		playAgainButton.setFillColor(sf::Color::Green);
		playAgainButton.setStyle(sf::Text::Style::Regular);
	}

	//Exit Button
	if (exitButton.getGlobalBounds().contains(mousePos)) {
		exitButton.setFillColor(sf::Color::Red);
		exitButton.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	}
	else {
		exitButton.setFillColor(sf::Color::Green);
		exitButton.setStyle(sf::Text::Style::Regular);
	}
}

void PlayAgainMenu::Draw(sf::RenderWindow& window, GameState state, const std::string& mainWord) {

	if (state == GameState::Won) {
		message_.setString("Congratulations, you won");
		message_.setOutlineThickness(1);
		message_.setCharacterSize(22);
		message_.setFillColor(sf::Color::Yellow);
		message_.setStyle(sf::Text::Style::Bold);

		sf::FloatRect won = message_.getLocalBounds();
		message_.setOrigin({ won.size.x / 2.f, won.size.y / 2.f });
		message_.setPosition({ 520,200 });
		window.draw(WinBackgroundSpr_);

		wordWas_.setString("The word was: " + mainWord);
		wordWas_.setCharacterSize(30);
		wordWas_.setFillColor(sf::Color::Red);
		wordWas_.setOutlineThickness(2);
		wordWas_.setStyle(sf::Text::Style::Bold);

		sf::FloatRect word = wordWas_.getLocalBounds();
		wordWas_.setOrigin({ word.size.x / 2.f, word.size.y / 2.f });
		wordWas_.setPosition({ gConfig.windowSize.x / 2 + 10, 240 });

		playAgainButton.setPosition({ gConfig.windowSize.x / 2 + 30, 300 });
		exitButton.setPosition({ gConfig.windowSize.x / 2 + 15, 365 });
	}
	else {
		window.draw(LoseBackgroundSpr_);
		message_.setString("You lost");
		message_.setOutlineThickness(2);
		message_.setCharacterSize(35);
		message_.setFillColor(sf::Color::Yellow);
		message_.setStyle(sf::Text::Style::Bold);

		wordWas_.setString("The word was: " + mainWord);
		wordWas_.setCharacterSize(30);
		wordWas_.setFillColor(sf::Color::Red);
		wordWas_.setOutlineThickness(2);
		wordWas_.setStyle(sf::Text::Style::Bold);

		sf::FloatRect word = wordWas_.getLocalBounds();
		wordWas_.setOrigin({ word.size.x / 2.f, word.size.y / 2.f });
		wordWas_.setPosition({ gConfig.windowSize.x / 2 + 10, 215 });

		sf::FloatRect lost = message_.getLocalBounds();
		message_.setOrigin({ lost.size.x / 2.f, lost.size.y / 2.f });
		message_.setPosition({ gConfig.windowSize.x  / 2, 150 });

		playAgainButton.setPosition({ gConfig.windowSize.x / 2 + 25, 280 });
		exitButton.setPosition({ gConfig.windowSize.x / 2 + 10, 362 });
	}

	window.draw(message_);
	window.draw(wordWas_);
	window.draw(playAgainButton);
	window.draw(exitButton);
}
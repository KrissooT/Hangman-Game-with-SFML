#include "PlayAgainMenu.h"

PlayAgainMenu::PlayAgainMenu() :
	font_("Content/Fonts/Font.ttf"),
	playAgainButton(font_),
	message_(font_),
	wordWas_(font_),
	exitButton(font_)
{
	//Play Again Button
	playAgainButton.setString("Play again ?");
	playAgainButton.setCharacterSize(50);
	playAgainButton.setFillColor(sf::Color::Green);

	playAgainButton.setOrigin(playAgainButton.getGlobalBounds().getCenter());
	playAgainButton.setPosition({ gConfig.windowSize.x / 2, gConfig.windowSize.y / 2 });

	//Exit Button
	exitButton.setString("Exit");
	exitButton.setCharacterSize(50);
	exitButton.setFillColor(sf::Color::Green);

	exitButton.setOrigin(exitButton.getGlobalBounds().getCenter());
	exitButton.setPosition({ gConfig.windowSize.x / 2, 500 });
}

GameState PlayAgainMenu::HandleClick(const sf::Vector2f& mousePos)const {

	if (playAgainButton.getGlobalBounds().contains(mousePos)) {
		return GameState::DifficultyMenu;
	}

	if (exitButton.getGlobalBounds().contains(mousePos)) {
		return GameState::Exit;
	}
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
		message_.setString("Congratulations, you won!");
		message_.setCharacterSize(50);
		message_.setFillColor(sf::Color::Yellow);

		sf::FloatRect won = message_.getLocalBounds();
		message_.setOrigin({ won.size.x / 2.f, won.size.y / 2.f });
		message_.setPosition({ gConfig.windowSize.x / 2 ,200 });
	}
	else {
		message_.setString("You lost!");
		message_.setCharacterSize(50);
		message_.setFillColor(sf::Color::Yellow);

		sf::FloatRect lost = message_.getLocalBounds();
		message_.setOrigin({ lost.size.x / 2.f, lost.size.y / 2.f });
		message_.setPosition({ gConfig.windowSize.x / 2, 200 });
	}

	//The word was
	wordWas_.setString("The word was: " + mainWord);
	wordWas_.setCharacterSize(50);
	wordWas_.setFillColor(sf::Color::Red);

	sf::FloatRect word = wordWas_.getLocalBounds();
	wordWas_.setOrigin({ word.size.x / 2.f, word.size.y / 2.f });
	wordWas_.setPosition({ gConfig.windowSize.x / 2, 300 });

	window.draw(message_);
	window.draw(wordWas_);
	window.draw(playAgainButton);
	window.draw(exitButton);
}
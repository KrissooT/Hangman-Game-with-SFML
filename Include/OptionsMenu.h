#pragma once

#include <SFML/Graphics.hpp>

#include "GameConfig.h"
#include "GameState.h"
#include "AudioManager.h"
#include "OptionsActions.h"

class OptionsMenu {

	private:

		sf::Texture backgroundTex_;
		sf::Sprite backgroundSpr_;

		sf::Font font_;
		sf::Font fontVolume_;
		
		sf::Text optionsText_;
		sf::Text musicVolumeText_;
		sf::Text soundVolumeText_;
		sf::Text backButton_;

		// +/- buttons and display for Music Volume
		sf::Text displayMusicVolume_;
		sf::Text plusMusicButton_;
		sf::Text minusMusicButton_;

		sf::Text musicMute_;
		sf::RectangleShape musicMuteBox_;

		// +/- buttons and display for Sound Volume
		sf::Text displaySoundVolume_;
		sf::Text plusSoundButton_;
		sf::Text minusSoundButton_;

		sf::Text soundMute_;
		sf::RectangleShape soundMuteBox_;

	public:

		OptionsMenu();

		OptionsActions HandleClick(const sf::Vector2f& MousePos);
		void UpdateVolumeText();
		void UpdateMuteBox();

		GameState Back(const sf::Vector2f& MousePos);
		void UpdateHover(const sf::Vector2f& MousePos);

		void Draw(sf::RenderWindow& window);

};
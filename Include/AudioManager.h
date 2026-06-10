#pragma once

#include <SFML/Audio.hpp>

#include "MusicState.h"

class AudioManager {
	private:
		MusicState musicState_ = MusicState::None;
		sf::Music music_;
	public:
		AudioManager();

		void PlayMenuMusic();
		void PlayGameMusic();
		void StopMusic();

		MusicState GetMusicState()const;

	private:
		//Mouse
		sf::SoundBuffer mBuffer_;
		sf::Sound mSound_;

		//Keyboard
		sf::SoundBuffer kBuffer_;
		sf::Sound kSound_;
	public:

		void PlayMouseClick();
		void PlayKeyPress();
};
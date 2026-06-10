#pragma once

#include <SFML/Audio.hpp>

#include "MusicState.h"

class AudioManager {
	private:
		sf::Music music_;
		MusicState musicState_ = MusicState::None;
	public:
		void PlayMenuMusic();
		void PlayGameMusic();
		void StopMusic();

		MusicState GetMusicState()const;
};
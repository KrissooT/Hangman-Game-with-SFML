#pragma once

#include <SFML/Audio.hpp>

#include "MusicState.h"
#include "GameConfig.h"

class AudioManager {
	private:
		MusicState musicState_ = MusicState::None;
		sf::Music music_;

	public:
		AudioManager();

		void PlayMenuMusic();
		void PlayGameMusic();
		void PlayWinMusic();
		void PlayLoseMusic();
		void PauseMusic();
		void ResumeMusic();

		MusicState GetMusicState()const;

		void SetMusicVolume(float value);
		void SetSoundVolume(float value);

		void ToggleMusicMute();
		void ToggleSoundMute();

		void UpdateVolume();

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
#include "AudioManager.h"

AudioManager::AudioManager() : 
	mBuffer_("Content/Audio/MouseClick.wav"),
	mSound_(mBuffer_),
	kBuffer_("Content/Audio/KeyboardClick.wav"),
	kSound_(kBuffer_)
{
}

void AudioManager::PlayMenuMusic() {
	if (musicState_ == MusicState::Menu) {
		return;
	}

	music_.openFromFile("Content/Audio/MainMenuMusic.mp3");
	music_.setLooping(true);
	music_.play();

	musicState_ = MusicState::Menu;
}

void AudioManager::PlayGameMusic() {
	if (musicState_ == MusicState::Game) {
		return;
	}

	music_.stop();
	music_.openFromFile("Content/Audio/GameMusic.mp3");
	music_.setLooping(true);
	music_.play();

	musicState_ = MusicState::Game;
}

void AudioManager::StopMusic() {
	music_.stop();
}

MusicState AudioManager::GetMusicState()const {
	return musicState_;
}

void AudioManager::PlayMouseClick() {
	mSound_.play();
}

void AudioManager::PlayKeyPress() {
	kSound_.play();
}
#include <algorithm>

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
	UpdateVolume();
	music_.play();

	musicState_ = MusicState::Menu;
}

void AudioManager::PlayGameMusic() {
	if (musicState_ == MusicState::Game) {
		return;
	}

	music_.stop();
	music_.openFromFile("Content/Audio/GameMusic.mp3");
	music_.setPlayingOffset(sf::seconds(1));
	music_.setLooping(true);
	UpdateVolume();
	music_.play();

	musicState_ = MusicState::Game;
}

void AudioManager::PlayWinMusic() {

	if (musicState_ == MusicState::Win) {
		return;
	}

	music_.stop();
	music_.openFromFile("Content/Audio/WinMusic.mp3");
	music_.setLooping(true);
	UpdateVolume();
	music_.play();

	musicState_ = MusicState::Win;
}

void AudioManager::PlayLoseMusic() {

	if (musicState_ == MusicState::Lose) {
		return;
	}

	music_.stop();
	music_.openFromFile("Content/Audio/LoseMusic.mp3");
	music_.setPlayingOffset(sf::seconds(3));
	music_.setLooping(true);
	UpdateVolume();
	music_.play();

	musicState_ = MusicState::Lose;
}

void AudioManager::PauseMusic() {
	music_.pause();
}

void AudioManager::ResumeMusic() {
	music_.play();
}

MusicState AudioManager::GetMusicState()const {
	return musicState_;
}

void AudioManager::SetMusicVolume(float value) {
	gConfig.musicVolume = std::clamp(value, 0.f, 100.f);
}

void AudioManager::SetSoundVolume(float value) {
	gConfig.soundVolume = std::clamp(value, 0.f, 100.f);
}

void AudioManager::ToggleMusicMute() {
	gConfig.musicMute = !gConfig.musicMute;
	UpdateVolume();
}

void AudioManager::ToggleSoundMute() {
	gConfig.soundMute = !gConfig.soundMute;
	UpdateVolume();
}

void AudioManager::UpdateVolume() {
	music_.setVolume(gConfig.musicMute ? 0.f : gConfig.musicVolume);

	float soundVolume = gConfig.soundMute ? 0.f : gConfig.soundVolume;
	kSound_.setVolume(soundVolume);
	mSound_.setVolume(soundVolume);
}

void AudioManager::PlayMouseClick() {
	mSound_.play();
}

void AudioManager::PlayKeyPress() {
	kSound_.play();
}
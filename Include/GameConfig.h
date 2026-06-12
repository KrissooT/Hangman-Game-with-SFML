#pragma once

#include <SFML/System/Vector2.hpp>

#include <string>

struct GameConfig {
	std::string windowTitle;
	sf::Vector2f windowSize;
	float musicVolume;
	float soundVolume;
	bool musicMute;
	bool soundMute;

	GameConfig();
};

inline GameConfig gConfig;
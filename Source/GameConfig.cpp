#include "GameConfig.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <cassert>

GameConfig::GameConfig() {
	std::ifstream file("Content/GameConfig.json");
	assert(file);

	nlohmann::json json = nlohmann::json::parse(file);
	windowTitle = json["windowTitle"];
	windowSize.x = json["windowSize"][0];
	windowSize.y = json["windowSize"][1];
	musicVolume = json["musicVolume"];
	soundVolume = json["soundVolume"];
	musicMute = json["musicMute"];
	soundMute = json["soundMute"];
}

void GameConfig::Save()const {
	nlohmann::json json;

	json["windowTitle"] = windowTitle;
	json["windowSize"][0] = windowSize.x;
	json["windowSize"][1] = windowSize.y;
	json["musicVolume"] = musicVolume;
	json["soundVolume"] = soundVolume;
	json["musicMute"] = musicMute;
	json["soundMute"] = soundMute;

	std::ofstream file("Content/GameConfig.json");
	assert(file);

	file << json.dump(4);
}
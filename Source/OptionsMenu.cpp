#include "OptionsMenu.h"
#include "AudioManager.h"

OptionsMenu::OptionsMenu() :
	backgroundTex_("Content/Assets/Backgrounds/OptionsMenuBackground.png"),
	backgroundSpr_(backgroundTex_),
	font_("Content/Fonts/MenuFont.ttf"),
	optionsText_(font_),
	musicVolumeText_(font_),
	soundVolumeText_(font_),
	backButton_(font_),
	musicMute_(font_),
	soundMute_(font_),
	fontVolume_("Content/Fonts/PlayAgainFont.ttf"),
	displayMusicVolume_(fontVolume_),
	plusMusicButton_(fontVolume_),
	minusMusicButton_(fontVolume_),
	displaySoundVolume_(fontVolume_),
	plusSoundButton_(fontVolume_),
	minusSoundButton_(fontVolume_)
{
	//Background
	auto backgroundSize = backgroundTex_.getSize();
	float backgroundX = gConfig.windowSize.x / backgroundSize.x;
	float backgroundY = gConfig.windowSize.y / backgroundSize.y;
	backgroundSpr_.setScale({ backgroundX, backgroundY });

	//Options Text
	optionsText_.setString("Options");
	optionsText_.setCharacterSize(80);
	optionsText_.setFillColor(sf::Color::White);

	optionsText_.setOrigin(optionsText_.getGlobalBounds().getCenter());
	optionsText_.setPosition({gConfig.windowSize.x / 2, 160});

	//Music Volume Text
	musicVolumeText_.setString("Music Volume");
	musicVolumeText_.setCharacterSize(40);
	musicVolumeText_.setFillColor(sf::Color::White);

	musicVolumeText_.setOrigin(musicVolumeText_.getGlobalBounds().getCenter());
	musicVolumeText_.setPosition({ gConfig.windowSize.x / 2, 260 });

	// Display Actual Music Volume
	displayMusicVolume_.setString(std::to_string((int)gConfig.musicVolume));
	displayMusicVolume_.setCharacterSize(45);
	displayMusicVolume_.setFillColor(sf::Color::Green);

	displayMusicVolume_.setOrigin(displayMusicVolume_.getGlobalBounds().getCenter());
	displayMusicVolume_.setPosition({ gConfig.windowSize.x / 2, 320 });

	// Music '+' Button 
	plusMusicButton_.setString("+");
	plusMusicButton_.setCharacterSize(40);
	plusMusicButton_.setFillColor(sf::Color::White);

	plusMusicButton_.setOrigin(plusMusicButton_.getGlobalBounds().getCenter());
	plusMusicButton_.setPosition({600,320});

	//Music '-' Button
	minusMusicButton_.setString("-");
	minusMusicButton_.setCharacterSize(40);
	minusMusicButton_.setFillColor(sf::Color::White);

	minusMusicButton_.setOrigin(minusMusicButton_.getGlobalBounds().getCenter());
	minusMusicButton_.setPosition({ 400,320 });

	//Music Mute
	musicMute_.setString("Mute Music");
	musicMute_.setCharacterSize(40);
	musicMute_.setFillColor(sf::Color::White);

	musicMute_.setOrigin(musicMute_.getGlobalBounds().getCenter());
	musicMute_.setPosition({ 450,525 });

	//Music Mute Box
	musicMuteBox_.setSize({ 30,30 });
	musicMuteBox_.setOutlineThickness(3);
	musicMuteBox_.setOutlineColor(sf::Color::Black);

	musicMuteBox_.setOrigin(musicMuteBox_.getGlobalBounds().getCenter());
	musicMuteBox_.setPosition({600,525});

	//Sound Volume Text
	soundVolumeText_.setString("Sound Volume");
	soundVolumeText_.setCharacterSize(40);
	soundVolumeText_.setFillColor(sf::Color::White);

	soundVolumeText_.setOrigin(soundVolumeText_.getGlobalBounds().getCenter());
	soundVolumeText_.setPosition({ gConfig.windowSize.x / 2, 400 });

	// Display Actual Sound Volume
	displaySoundVolume_.setString(std::to_string((int)gConfig.soundVolume));
	displaySoundVolume_.setCharacterSize(45);
	displaySoundVolume_.setFillColor(sf::Color::Green);

	displaySoundVolume_.setOrigin(displaySoundVolume_.getGlobalBounds().getCenter());
	displaySoundVolume_.setPosition({ gConfig.windowSize.x / 2, 460 });

	// Sound '+' Button 
	plusSoundButton_.setString("+");
	plusSoundButton_.setCharacterSize(40);
	plusSoundButton_.setFillColor(sf::Color::White);

	plusSoundButton_.setOrigin(plusSoundButton_.getGlobalBounds().getCenter());
	plusSoundButton_.setPosition({ 600,460 });

	//Sound '-' Button
	minusSoundButton_.setString("-");
	minusSoundButton_.setCharacterSize(40);
	minusSoundButton_.setFillColor(sf::Color::White);

	minusSoundButton_.setOrigin(minusSoundButton_.getGlobalBounds().getCenter());
	minusSoundButton_.setPosition({ 400,460 });

	//Sound Mute
	soundMute_.setString("Mute Sound");
	soundMute_.setCharacterSize(40);
	soundMute_.setFillColor(sf::Color::White);

	soundMute_.setOrigin(soundMute_.getGlobalBounds().getCenter());
	soundMute_.setPosition({ 450,585 });

	//Sound Mute Box
	soundMuteBox_.setSize({ 30,30 });
	soundMuteBox_.setOutlineThickness(3);
	soundMuteBox_.setOutlineColor(sf::Color::Black);

	soundMuteBox_.setOrigin(soundMuteBox_.getGlobalBounds().getCenter());
	soundMuteBox_.setPosition({ 600,585 });

	//Back Button
	backButton_.setString("Back");
	backButton_.setCharacterSize(50);

	backButton_.setOrigin(backButton_.getGlobalBounds().getCenter());
	backButton_.setPosition({ gConfig.windowSize.x / 2, 667 });
}

OptionsActions OptionsMenu::HandleClick(const sf::Vector2f& MousePos) {

	if (plusMusicButton_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::MusicUp;
	}
	if (minusMusicButton_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::MusicDown;
	}
	if (plusSoundButton_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::SoundUp;
	}
	if (minusSoundButton_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::SoundDown;
	}
	if (musicMuteBox_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::MusicMute;
	}
	if (soundMuteBox_.getGlobalBounds().contains(MousePos)) {
		return OptionsActions::SoundMute;
	}

	return OptionsActions::None;
}

void OptionsMenu::UpdateVolumeText() {
	displayMusicVolume_.setString(std::to_string((int)gConfig.musicVolume));
	displaySoundVolume_.setString(std::to_string((int)gConfig.soundVolume));
}

void OptionsMenu::UpdateMuteBox() {
	musicMuteBox_.setFillColor(gConfig.musicMute ? sf::Color::Green : sf::Color::Red);
	soundMuteBox_.setFillColor(gConfig.soundMute ? sf::Color::Green : sf::Color::Red);
}

GameState OptionsMenu::Back(const sf::Vector2f& MousePos){
	if (backButton_.getGlobalBounds().contains(MousePos)) {
		return GameState::MainMenu;
	}
	return GameState::Options;
}

void OptionsMenu::UpdateHover(const sf::Vector2f& MousePos) {
	//Back Button
	if (backButton_.getGlobalBounds().contains(MousePos)) {
		backButton_.setFillColor(sf::Color::Red);
		backButton_.setStyle(sf::Text::Style::Bold);
	}
	else {
		backButton_.setFillColor(sf::Color::White);
		backButton_.setStyle(sf::Text::Style::Regular);
	}

	//Music '+' Button
	if (plusMusicButton_.getGlobalBounds().contains(MousePos)) {
		plusMusicButton_.setFillColor(sf::Color::Green);
		plusMusicButton_.setStyle(sf::Text::Style::Bold);
	}
	else {
		plusMusicButton_.setFillColor(sf::Color::White);
		plusMusicButton_.setStyle(sf::Text::Style::Regular);
	}

	//Music '-' Button
	if (minusMusicButton_.getGlobalBounds().contains(MousePos)) {
		minusMusicButton_.setFillColor(sf::Color::Red);
		minusMusicButton_.setStyle(sf::Text::Style::Bold);
	}
	else {
		minusMusicButton_.setFillColor(sf::Color::White);
		minusMusicButton_.setStyle(sf::Text::Style::Regular);
	}

	//Sound '+' Button
	if (plusSoundButton_.getGlobalBounds().contains(MousePos)) {
		plusSoundButton_.setFillColor(sf::Color::Green);
		plusSoundButton_.setStyle(sf::Text::Style::Bold);
	}
	else {
		plusSoundButton_.setFillColor(sf::Color::White);
		plusSoundButton_.setStyle(sf::Text::Style::Regular);
	}

	//Sound '-' Button
	if (minusSoundButton_.getGlobalBounds().contains(MousePos)) {
		minusSoundButton_.setFillColor(sf::Color::Red);
		minusSoundButton_.setStyle(sf::Text::Style::Bold);
	}
	else {
		minusSoundButton_.setFillColor(sf::Color::White);
		minusSoundButton_.setStyle(sf::Text::Style::Regular);
	}
}

void OptionsMenu::Draw(sf::RenderWindow& window) {
	window.draw(backgroundSpr_);
	window.draw(optionsText_);

	window.draw(musicVolumeText_);
	window.draw(displayMusicVolume_);
	window.draw(plusMusicButton_);
	window.draw(minusMusicButton_);
	window.draw(musicMute_);
	window.draw(musicMuteBox_);

	window.draw(soundVolumeText_);
	window.draw(displaySoundVolume_);
	window.draw(plusSoundButton_);
	window.draw(minusSoundButton_);
	window.draw(soundMute_);
	window.draw(soundMuteBox_);

	window.draw(backButton_);
}
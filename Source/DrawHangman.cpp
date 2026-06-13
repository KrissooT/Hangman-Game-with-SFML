#include "DrawHangman.h"

#include <algorithm>

DrawHangman::DrawHangman():
	emptyTexture_("Content/Assets/Backgrounds/EmptyBackground.png"),
	sprite_(emptyTexture_)
{
	head_.loadFromFile("Content/Assets/HangmanSprites/Head.png");
	torso_.loadFromFile("Content/Assets/HangmanSprites/HeadAndBody.png");
	leftArm_.loadFromFile("Content/Assets/HangmanSprites/HeadBodyLeftArm.png");
	rightArm_.loadFromFile("Content/Assets/HangmanSprites/HeadBodyBothArms.png");
	leftLeg_.loadFromFile("Content/Assets/HangmanSprites/HeadBodyBothArmsLeftLeg.png");
}

void DrawHangman::Draw(sf::RenderWindow& window, int lives)
{
	int stage = std::clamp(6 - lives, 0, 5);

	lives = 6 - lives;
	
	sprite_.setTexture(emptyTexture_);  //Resets the drawing

	if (lives == 1) {
		//Head
		sprite_.setTexture(head_,true);
		sprite_.setScale({ 0.6f, 0.6f });
		sprite_.setPosition({ 393.f, 235.f });
	}
	if (lives == 2) {
		//Torso
		sprite_.setTexture(torso_, true);
		sprite_.setScale({ 1.f, 1.0f });
		sprite_.setPosition({ 413.f, 295.f });
	}
	if (lives == 3) {
		//Left Arm
		sprite_.setTexture(leftArm_, true);
		sprite_.setScale({ 1.1f, 1.1f });
		sprite_.setPosition({ 418.f, 300.f });
	}
	if (lives == 4) {
		//Both Arms
		sprite_.setTexture(rightArm_, true);
		sprite_.setScale({ 1.22f, 1.1f });
		sprite_.setPosition({ 408.f, 300.f });
	}
	if (lives == 5) {
		//Left Leg
		sprite_.setTexture(leftLeg_, true);
		sprite_.setScale({ 1.25f, 1.35f });
		sprite_.setPosition({ 408.f, 350.f });
	}

	auto bounds = sprite_.getLocalBounds();
	sprite_.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });

	window.draw(sprite_);
}
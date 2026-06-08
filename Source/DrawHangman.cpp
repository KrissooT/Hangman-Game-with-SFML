#include "DrawHangman.h"

#include <algorithm>

DrawHangman::DrawHangman():
	emptyTexture_("Content/Textures/Empty.png"),
	sprite_(emptyTexture_)
{
	head_.loadFromFile("Content/Textures/Head.png");
	torso_.loadFromFile("Content/Textures/HeadAndBody.png");
	leftArm_.loadFromFile("Content/Textures/HeadBodyLeftArm.png");
	rightArm_.loadFromFile("Content/Textures/HeadBodyBothArms.png");
	rightArm_.setSmooth(true);
	leftLeg_.loadFromFile("Content/Textures/HeadBodyBothArmsLeftLeg.png");
	leftLeg_.setSmooth(true);
	dead_.loadFromFile("Content/Textures/Dead.png");
}

void DrawHangman::Draw(sf::RenderWindow& window, int lives)
{
	int stage = std::clamp(6 - lives, 0, 5);

	lives = 6 - lives;

	auto bounds = sprite_.getLocalBounds();
	sprite_.setOrigin({ bounds.size.x / 2.f, bounds.size.y / 2.f });

	if (lives == 1) {
		//Head
		sprite_.setTexture(head_);
		sprite_.setScale({ 1.f, 1.f });
		sprite_.setPosition({ 540.f, 325.f });
	}
	if (lives == 2) {
		//Torso
		sprite_.setTexture(torso_);
		sprite_.setScale({ 1.f, 1.f });
		sprite_.setPosition({ 525.f, 365.f });
	}
	if (lives == 3) {
		//Left Arm
		sprite_.setTexture(leftArm_);
		sprite_.setScale({ 0.7f, 0.7f });
		sprite_.setPosition({ 480.f, 400.f });
	}
	if (lives == 4) {
		//Both Arms
		sprite_.setTexture(rightArm_);
		sprite_.setScale({ 0.75f, 0.75f });
		sprite_.setPosition({ 445.f, 425.f });
	}
	if (lives == 5) {
		//Left Leg
		sprite_.setTexture(leftLeg_);
		sprite_.setScale({ 0.8f, 0.8f });
		sprite_.setPosition({ 455.f, 475.f });
	}
	window.draw(sprite_);
}
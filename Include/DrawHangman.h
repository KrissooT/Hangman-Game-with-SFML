#pragma once

#include <SFML/Graphics.hpp>

class DrawHangman {
    private:

        sf::Texture emptyTexture_;
        //sf::Texture textures_[6];
        sf::Texture head_;
        sf::Texture torso_;
        sf::Texture leftArm_;
        sf::Texture rightArm_;
        sf::Texture leftLeg_;
        sf::Texture dead_;
        sf::Sprite sprite_;


    public:
        DrawHangman();

        void Draw(sf::RenderWindow& window, int lives);
};
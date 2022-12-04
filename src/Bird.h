//
// Created by Jaidenmagnan on 12/3/22.
//

#pragma once
#include <SFML/System/Vector2.hpp>
#include "SFML/Graphics.hpp"
#include "Toolbox.h"

class Bird {
private:
    sf::Texture birdTexture;
    float velocity;
    float gravity;
    float lift;

    sf::Vector2f pos;

public:
    Bird();
    void zeroVelocity();
    bool checkCollision(sf::Vector2f check);
    void draw();
    void updatePosition(bool click);
    sf::Vector2f getPosition();
};



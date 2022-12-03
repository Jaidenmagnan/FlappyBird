//
// Created by Jaidenmagnan on 12/3/22.
//

#include <iostream>
#include "Bird.h"

Bird::Bird() {
    pos = {300, 200};
    velocity = 0;
    gravity = .0002;
    lift = -.5;
}

void Bird::draw() {
    if (this->velocity < .1) {
        birdTexture.loadFromFile("assets/Flying.png", sf::IntRect(96, 0, 32, 32));
    }
    else {
        birdTexture.loadFromFile("assets/Flying.png", sf::IntRect(0, 0, 32, 32));
    }

    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setPosition(pos);
    bird.scale({-3,3});

    Toolbox& toolbox = Toolbox::getInstance();
    toolbox.window.draw(bird);

}

void Bird::updatePosition(bool click) {
    Toolbox &toolbox = Toolbox::getInstance();
    this->velocity += this->gravity;
    pos.y += this->velocity;

    if(pos.y > toolbox.SCREEN_HEIGHT - 300) {
        this->velocity = 0;
        pos.y = toolbox.SCREEN_HEIGHT - 300;
    }

    if(pos.y < 0) {
        this->velocity = 0;
        pos.y = 0;
    }

    if (click) {
        this->velocity += lift;
    }
}

bool Bird::checkCollision(sf::Vector2f check) {
    return check.y == this->pos.y;
}

sf::Vector2f Bird::getPosition() {
    return pos;
}

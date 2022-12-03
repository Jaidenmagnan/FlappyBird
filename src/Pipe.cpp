//
// Created by Jaidenmagnan on 12/3/22.
//

#include <iostream>
#include "Pipe.h"

Pipe::Pipe(int x) {
    Toolbox &toolbox = Toolbox::getInstance();
    int height = random() % (toolbox.SCREEN_HEIGHT / 2);
    topPipePos = {float(x), float(height)};
    botPipePos = {float(x-104), topPipePos.y + 400};

}

bool Pipe::checkCollision(sf::Vector2f bird) const {

    if(bird.x + 96 >= topPipePos.x && bird.y < topPipePos.y && bird.x <= topPipePos.x + 104 ) {
        return true;
    }
    else if(bird.x + 96 >= botPipePos.x && bird.y - 96 > botPipePos.y && bird.x <=botPipePos.x + 104) {
        return true;
    }
    else {
        return false;
    }

}

void Pipe::reset() {
    if(topPipePos.x < 0) {
        Toolbox &toolbox = Toolbox::getInstance();
        int height = (random()) % (toolbox.SCREEN_HEIGHT / 2);
        topPipePos = {float(1200) + 400, float(height)};
        botPipePos = {float(1200-104) + 400, topPipePos.y + 400};
    }

}

void Pipe::draw() {
    Toolbox& toolbox = Toolbox::getInstance();

    topPipeTexture.loadFromFile("assets/GreenPipe.png");
    sf::Sprite topPipeSprite;

    topPipeSprite.setTexture(topPipeTexture);
    topPipeSprite.setPosition(topPipePos);
    topPipeSprite.scale({2,2});
    topPipeSprite.rotate(180);

    toolbox.window.draw(topPipeSprite);

    botPipeTexture.loadFromFile("assets/GreenPipe.png");
    sf::Sprite botPipeSprite;

    botPipeSprite.setTexture(botPipeTexture);
    botPipeSprite.setPosition(botPipePos);
    botPipeSprite.scale({2, 2});

    toolbox.window.draw(botPipeSprite);

}

void Pipe::move(bool playing) {
    if (playing) {
        float speed = .3;
        botPipePos.x -= speed;
        topPipePos.x -= speed;
    }

}


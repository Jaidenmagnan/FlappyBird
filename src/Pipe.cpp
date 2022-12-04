//
// Created by Jaidenmagnan on 12/3/22.
//

#include <iostream>
#include "Pipe.h"

Pipe::Pipe(int x) { //constructor for pipes
    Toolbox &toolbox = Toolbox::getInstance();

    int height = ((random() -200 ) % ((toolbox.SCREEN_HEIGHT) / 2));
    topPipePos = {float(x), float(height)};
    botPipePos = {float(x-104), topPipePos.y + 400};

}

void Pipe::addPoint(sf::Vector2f bird) const { //adds a point if the user passes the pipes
    Toolbox &toolbox = Toolbox::getInstance();
    if(botPipePos.x == 300) {
        toolbox.score += 1;
    }

}
bool Pipe::checkCollision(sf::Vector2f bird) const { //checks collision with the bird
    Toolbox &toolbox = Toolbox::getInstance();

    if(bird.x  > topPipePos.x - 104 && bird.y < topPipePos.y && bird.x < topPipePos.x + 104 ) {
        return true;
    }
    else if(bird.x > botPipePos.x && bird.y + 96 >= botPipePos.y && bird.x - 96 < botPipePos.x + 104) {
        return true;
    }
    else {
        return false;
    }

}

void Pipe::reset() { //resets each pipe so they wrap around
    if(topPipePos.x < 0) {
        Toolbox &toolbox = Toolbox::getInstance();
        toolbox.score += 1;
        int height = ((random() -200 ) % ((toolbox.SCREEN_HEIGHT) / 2));
        topPipePos = {float(1600) , float(height)};
        botPipePos = {float(1600 - 104) , topPipePos.y + 400};
    }

}

void Pipe::draw() { //draws the pipes to the screen
    Toolbox& toolbox = Toolbox::getInstance();


    sf::Sprite topPipeSprite;
    topPipeTexture.loadFromFile("assets/GreenPipe.png");
    botPipeTexture.loadFromFile("assets/GreenPipe.png");


    topPipeSprite.setTexture(topPipeTexture);
    topPipeSprite.setPosition(topPipePos);
    topPipeSprite.scale({2,2});
    topPipeSprite.rotate(180);

    toolbox.window.draw(topPipeSprite);

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


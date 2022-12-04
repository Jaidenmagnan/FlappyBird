//
// Created by Jaidenmagnan on 12/3/22.
//

#pragma once
#include "Toolbox.h"

class Pipe {
public:
    explicit Pipe(int x);
    void draw();
    void move(bool playing);
    void reset();
    bool checkCollision(sf::Vector2f bird) const;
    void addPoint(sf::Vector2f bird) const;

    int x;

private:
    sf::Texture topPipeTexture;
    sf::Texture botPipeTexture;

    sf::Vector2f topPipePos;
    sf::Vector2f botPipePos;



};


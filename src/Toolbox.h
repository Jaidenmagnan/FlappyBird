//
// Created by Jaidenmagnan on 12/3/22.
//


#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

class Toolbox {

public:
    static Toolbox& getInstance();
    sf::RenderWindow window;
    int SCREEN_HEIGHT = 768;
    bool playing = false;
    int score;

private:
    static Toolbox toolbox;
    ~Toolbox();
    Toolbox();

};



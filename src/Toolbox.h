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
    int SCREEN_HEIGHT = 1000;
    int SCREEN_WIDTH = 800;

private:
    static Toolbox toolbox;
    ~Toolbox();
    Toolbox();

};



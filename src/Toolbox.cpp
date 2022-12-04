//
// Created by Jaidenmagnan on 12/3/22.
//

#include "Toolbox.h"

Toolbox &Toolbox::getInstance() { //gets our singleton of the toolbox class
    static Toolbox toolbox;
    return toolbox;

}


Toolbox::~Toolbox() = default;

Toolbox::Toolbox() :window(sf::VideoMode(1000, 768), "Flappy Bird" , (sf::Style::Titlebar, sf::Style::Close)) {
    score = 1;
}

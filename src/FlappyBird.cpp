//
// Created by Jaidenmagnan on 12/3/22.


#include "Toolbox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"
#include "Pipe.h"


void render();
void launch();
void gameLoop();

void launch() { //launches the game loop
    gameLoop();
}


void gameLoop() { //loops through game
    int playing = true;
    Toolbox &toolbox = Toolbox::getInstance();
    toolbox.window.setKeyRepeatEnabled(false);
    Bird *bird = new Bird();
    std::vector<Pipe*> pipes = {new Pipe(1000),new Pipe(1400),new Pipe(1800), new Pipe(2200) };

    sf::Font font;
    font.loadFromFile("assets/Cave-Story.ttf");

    sf::Text scoreText;

    while(toolbox.window.isOpen()) {
        //Event polling
        sf::Event event{};
        bool mouseClick = false;

        while (toolbox.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                toolbox.window.close();
            }

            if (event.type == sf::Event::KeyPressed && playing) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    mouseClick = true;
                }

            }
        }

        if(bird->checkCollision({0,float(toolbox.SCREEN_HEIGHT - 300)})) {
            playing = false;
        }

        //toolbox.window.clear(sf::Color::Blue); //changes color to blue
        bird->updatePosition(mouseClick);
        toolbox.window.clear();
        for(Pipe* pipe : pipes) {
            pipe->draw();
            pipe->reset();
            pipe->move(playing);
            pipe->addPoint(bird->getPosition());
            if (pipe->checkCollision(bird->getPosition())) {
                playing = false;
            }
        }
        bird->draw();

        scoreText.setFont(font);
        scoreText.setCharacterSize(100);
        scoreText.setString(std::to_string(toolbox.score));
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(100, 40);

        toolbox.window.draw(scoreText);
        toolbox.window.display();


    }
}

int main() {
    launch();
    Toolbox &toolbox = Toolbox::getInstance();
    std::cout << toolbox.score;
    return 0;
}
//
// Created by Jaidenmagnan on 12/3/22.


#include "Toolbox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"
#include "Pipe.h"


void launch();
void gameLoop();

void launch() { //launches the game loop
    gameLoop();
}


void gameLoop() { //loops through game
    Toolbox &toolbox = Toolbox::getInstance();
    bool &playing = toolbox.playing;
    toolbox.window.setKeyRepeatEnabled(false);

    //initializes sprites
    Bird *bird = new Bird();
    std::vector<Pipe*> pipes = {new Pipe(1000),new Pipe(1400),new Pipe(1800), new Pipe(2200) };

    //loads the fonts
    sf::Font font;
    font.loadFromFile("assets/Cave-Story.ttf");
    sf::Text scoreText;

    sf::Texture backgroundTexture;

    backgroundTexture.loadFromFile("assets/background.png");
    sf::Sprite background;
    background.setTexture(backgroundTexture);

    //the game loop itself
    while(toolbox.window.isOpen()) {
        //Event polling
        sf::Event event{};
        bool mouseClick = false;

        while (toolbox.window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                toolbox.window.close();
            }

            if (event.type == sf::Event::KeyPressed && playing) { //checks if the user presses the space bar
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    mouseClick = true;
                }

            }

            if(playing == false) { //resets the game if lost
                if (event.type == sf::Event::KeyPressed) { //checks if the user presses the space bar
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        playing = true;
                        toolbox.score = 1;
                        pipes.clear();
                        pipes = {new Pipe(1000),new Pipe(1400),new Pipe(1800), new Pipe(2200) };
                        delete bird;
                        bird = new Bird();
                    }
                    }

            }
        }

        if(bird->checkCollision({0,float(toolbox.SCREEN_HEIGHT - 300)})) { //checks for collision with the ground
            playing = false;
        }

        //toolbox.window.clear(sf::Color::Blue); //changes color to blue
        bird->updatePosition(mouseClick);
        toolbox.window.clear();
        toolbox.window.draw(background);
        for(Pipe* pipe : pipes) { //pipe logic
            pipe->draw();
            pipe->reset();
            pipe->move(playing);
            pipe->addPoint(bird->getPosition());
            if (pipe->checkCollision(bird->getPosition())) { //checks if the bird hits the pipes
                playing = false;
                bird->zeroVelocity();
            }
        }
        bird->draw();

        scoreText.setFont(font); //renders things to the screen
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
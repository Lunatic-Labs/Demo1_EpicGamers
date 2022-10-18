#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Player.h"
#include "../include/Ground.h"

static const float VIEW_WIDTH = 640.0F; //affect aspect ratio of window
static const float VIEW_HEIGHT = 360.0F;

void resizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}


int main()
{
    // create and setup window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dog Dash!");
    sf::Image icon;
    icon.loadFromFile("Textures/LUlogo.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::View view(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(VIEW_WIDTH,VIEW_HEIGHT));

    // init important variables
    float gameSpeed = 1.75;                     // lower gameSpeed = faster movement
    float gameSpeedLimit = 1.25;                // gameSpeed variable cannot decrease below this limit
    float gameSpeedModifier = 0.05;             // change the speed by *this* much
    int incrementWaitTime = 14;                 // increases speed every x seconds
    int loopCounter = 1;                        // tracks the number of speed increment loops
    bool isJumping = false;                     // prevents multiple simultaneous jump inputs
    float deltaTime = 0.0f, totalTime = 0.0f;
    sf::Clock clock, jumpTimer;
  
    // load player and ground textures and init objects
    sf::Texture dogPlayer, groundScroll;
    dogPlayer.loadFromFile("Textures/dogRunnerWIP2.jpg");
    groundScroll.loadFromFile("Textures/SidewalkWIP1.jpg"); //Need to set up as an object with collision
    Player player(&dogPlayer, sf::Vector2u(10, 2), 0.09f, 100.0f);
    Ground ground(&groundScroll, sf::Vector2u(4, 1), 0.09f, 100.0f);

    // core game loop
    while (window.isOpen()) {
        // manage time since last frame
        totalTime += clock.getElapsedTime().asSeconds();
        deltaTime = clock.restart().asSeconds();

        // handle events
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            //Check the type of the event
            switch (evnt.type) {
                // process window events
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
                // process key presses
                case sf::Event::KeyPressed: 
                    // spacebar -> jump
                    if (evnt.key.code == 57 && isJumping == false) {   
                        isJumping = true;
                        player.Update(deltaTime, isJumping, gameSpeed-0.25);        //(gameSpeed-0.25) is exclusive to Player.Update function call and only affects visual speed
                    }
                    break;
                // process key releases
                case sf::Event::KeyReleased:
                    if (evnt.key.code == 57) {
                        isJumping = false;
                    }
                    break;
            }
        }

        // process player
        player.Update(deltaTime, isJumping, gameSpeed-0.25);
        ground.Update(deltaTime, gameSpeed);
        view.setCenter(player.getPosition());

        // clear the window and draw the next frame
        window.clear();
        window.setView(view);
        player.Draw(window);
        ground.Draw(window);
        window.display();

        // increase speed if needed, with an upper limit. Again, lower gameSpeed = faster movement
        if (totalTime > (incrementWaitTime*loopCounter) && gameSpeed > gameSpeedLimit) {
            loopCounter++;
            gameSpeed -= gameSpeedModifier;
            std::cout << "Speed increase!\n" << gameSpeed << std::endl;
        }
    }
    return 0;
}

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


//main function 
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dog Dash!");
    sf::Image icon;
    icon.loadFromFile("Textures/LUlogo.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::View view(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(VIEW_WIDTH,VIEW_HEIGHT));

    // init important variables
    float gameSpeed = 1.75;                     // lower gameSpeed = faster movement.
    float gameSpeedLimit = 1.25;                // gameSpeed variable cannot decrease below this limit
    float gameSpeedModifier = 0.05;             // change the speed by *this* much
    int incrementWaitTime = 14;                 // increases speed every x seconds
    int loopCounter = 1;                        // tracks the number of speed increment loops
    float deltaTime = 0.0f, totalTime = 0.0f;
    
  
    // load player and ground textures and init objects
    sf::Texture dogPlayer, groundScroll;
    dogPlayer.loadFromFile("Textures/dogRunnerWIP2.jpg");
    groundScroll.loadFromFile("Textures/SidewalkWIP1.jpg"); //Need to set up as an object with collision
    Player player(&dogPlayer, sf::Vector2u(10, 2), 0.09f, 100.0f);
    Ground ground(&groundScroll, sf::Vector2u(4, 1), 0.09f, 100.0f);

    sf::Clock clock, jumpTimer;
    bool isJumping = false;                     // prevents multiple simultaneous jump inputs


    // core game loop
    while (window.isOpen())     
    {
        totalTime += clock.getElapsedTime().asSeconds();    //Total game time
        deltaTime = clock.restart().asSeconds();            //Time each loop, < 1.0s

        // handle events
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            //Check the type of the event
            switch (evnt.type) {
                // window events
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
                // keyboard input
                case sf::Event::KeyPressed: 
                    // spacebar -> jump
                    if (evnt.key.code == 57 && isJumping == false) {   
                        isJumping = true;
                        player.Update(deltaTime, isJumping, gameSpeed-0.25);        // !! question- what is the 0.25 for? Let's use variables (with documentation comments) for these types of things.
                    }
                    break;
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

        // increase speed, with an upper limit
        // lower speed == faster scroll with this animation functionality
        if (totalTime > (incrementWaitTime*loopCounter) && gameSpeed > gameSpeedLimit) {
            loopCounter++;
            gameSpeed -= gameSpeedModifier;
            std::cout << "Speed increase!\n" << gameSpeed << std::endl;
        }
    }
    return 0;
}

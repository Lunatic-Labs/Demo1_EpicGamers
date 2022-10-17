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
    // load player
    sf::Texture dogPlayer, groundScroll;
    dogPlayer.loadFromFile("Textures/dogRunnerWIP2.jpg");
    groundScroll.loadFromFile("Textures/SidewalkWIP1.jpg"); //Need to set up as an object with collision
    Player player(&dogPlayer, sf::Vector2u(10, 2), 0.09f, 100.0f);
    Ground ground(&groundScroll, sf::Vector2u(4, 1), 0.09f, 100.0f);
    float gameSpeed = 1.75;   //determines how fast ground scrolls. Use to speed up obstacle spawning as well?

    // create deltatime
    float deltaTime = 0.0f, totalTime = 0.0f;
    int loop = 1;
    sf::Clock clock, jumpTimer;
    bool isJumping = false;     //Used in switch, prevent multiple space inputs when holding key
    while (window.isOpen())     // core game loop
    {
        totalTime += clock.getElapsedTime().asSeconds();    //Total game time
        deltaTime = clock.restart().asSeconds();            //Time each loop, < 1.0s

        sf::Event evnt;
        while (window.pollEvent(evnt))  //While there are pending events...
        {
            switch (evnt.type)          //Check the type of the event
            {
            case sf::Event::Closed:     // close window if exited
                window.close();
                break;
            case sf::Event::Resized:
                resizeView(window, view);
                break;   
            case sf::Event::KeyPressed: //update player immediately if key pressed
                //Key code 57 is Spacebar
                if (evnt.key.code == 57 && isJumping == false)
                {   
                    isJumping = true;
                    player.Update(deltaTime, isJumping, gameSpeed-0.25);
                }
                break;
            case sf::Event::KeyReleased:
                if (evnt.key.code == 57)
                {
                    isJumping = false;
                }
                break;
            //Triggering events: https://www.sfml-dev.org/tutorials/2.5/window-events.php
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

        if (totalTime > (14*loop) && gameSpeed > 1.25)      //increase speed every 14.0s, with an upper limit
        {                                                   //(lower speed == faster scroll with this animation functionality)
            loop++;
            gameSpeed -= 0.05;
            std::cout << "Speed increase!\n" << gameSpeed << std::endl;
        }
    }
    return 0;
}

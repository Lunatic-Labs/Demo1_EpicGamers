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
    dogPlayer.loadFromFile("Textures/dogRunnerWIP1.jpg");
    groundScroll.loadFromFile("Textures/SidewalkWIP1.jpg"); //Need to set up as an object with collision
    Player player(&dogPlayer, sf::Vector2u(10, 1), 0.09f, 100.0f);
    Ground ground(&groundScroll, sf::Vector2u(4, 1), 0.09f, 100.0f);

    // create deltatime
    float deltaTime = 0.0f; 
    sf::Clock clock;
    bool isJumping = false;  //Used in switch, prevent multiple space inputs when holding key
    // core game loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        std::cout << isJumping;

        // close window if exited
        sf::Event evnt;
        while (window.pollEvent(evnt))  //While there are pending events...
        {
            switch (evnt.type)  //Check the type of the event
            {
            case sf::Event::Closed:
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
                    player.Update(deltaTime, isJumping);
                }
            case sf::Event::KeyReleased:
                if (evnt.key.code == 57)
                {
                    isJumping = false;
                }
            //Triggering events: https://www.sfml-dev.org/tutorials/2.5/window-events.php
            }
        }

        // process player
        player.Update(deltaTime, isJumping);
        ground.Update(deltaTime);
        view.setCenter(player.getPosition());
        // clear the window and draw the next frame
        window.clear();
        window.setView(view);
        player.Draw(window);
        ground.Draw(window);
        window.display();
    }
    return 0;
}

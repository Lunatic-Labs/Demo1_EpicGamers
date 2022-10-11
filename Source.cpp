#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

static const float VIEW_WIDTH = 1920.0F;
static const float VIEW_HEIGHT = 1080.0F;

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
    sf::Texture dogPlayer;
    dogPlayer.loadFromFile("Textures/dogRunnerWIP1.jpg");
    Player player(&dogPlayer, sf::Vector2u(6, 2), 0.09f, 100.0f);

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
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                resizeView(window, view);
                break;   
            //Below: Justin's attempt to handle jumping as an event, 10/9/22
            case sf::Event::KeyPressed: //update player immediately if Spacebar's pressed
                if (Event.Key.Code == sf::Keyboard::Space && isJumping = false)
                {
                    player.Update(deltaTime);
                    isJumping = true;
                }
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space)
                {
                    isJumping = false;
                }
            //End Justin's attempt. Event.Key.Code not working? 
            //https://www.sfml-dev.org/tutorials/2.5/window-events.php
            }
        }

        // process player
        player.Update(deltaTime);
        view.setCenter(player.getPosition());
        // clear the window and draw the next frame
        window.clear();
        window.setView(view);
        player.Draw(window);
        window.display();
    }
    return 0;
}

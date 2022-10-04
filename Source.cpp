#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

    // load player
    sf::Texture dogPlayer;
    dogPlayer.loadFromFile("Textures/walkJump.png");
    Player player(&dogPlayer, sf::Vector2u(6, 2), 0.09f, 100.0f);

    // create time
    float deltaTime = 0.0f;
    sf::Clock clock;

    // core game loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        // close window if exited
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        // process player
        player.Update(deltaTime);

        // clear the window and draw the next frame
        window.clear();
        player.Draw(window);
        window.display();
    }

    return 0;
}
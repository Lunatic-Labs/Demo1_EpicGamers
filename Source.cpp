#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::Texture dogPlayer;
    dogPlayer.loadFromFile("Textures/walkJump.png");
    Player player(&dogPlayer, sf::Vector2u(6, 2), 0.09f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        player.Update(deltaTime);

        window.clear();
        player.Draw(window);
        window.display();
    }

    return 0;
}
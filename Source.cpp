#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::RectangleShape player(sf::Vector2f(250.0f, 220.0f));
    player.setPosition(100.0f, 250.0f);
    sf::Texture dogPlayer;
    dogPlayer.loadFromFile("Textures/googleDog.jpg");
    player.setTexture(&dogPlayer);

    Animation animation(&dogPlayer, sf::Vector2u(6, 2), 0.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;


    //Vector for Sprit
    /*sf::Vector2u textureSize = dogPlayer.getSize();
    textureSize.x /= 6;
    textureSize.y /= 2;

    player.setTextureRect(sf::IntRect(textureSize.x*5, textureSize.y*1, textureSize.x, textureSize.y));*/

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        animation.update(0, deltaTime);
        player.setTextureRect(animation.uvRect);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
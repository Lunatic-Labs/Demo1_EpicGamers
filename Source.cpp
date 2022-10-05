#include <SFML/Graphics.hpp>
#include "Player.h"

static const float VIEW_WIDTH = 1920.0F;
static const float VIEW_HEIGHT = 1080.0F;

void resizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dog Dash!");
    sf::View view(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(VIEW_WIDTH,VIEW_HEIGHT));
    // load player
    sf::Texture dogPlayer;
    dogPlayer.loadFromFile("Textures/walkJump.png");
    Player player(&dogPlayer, sf::Vector2u(6, 2), 0.09f, 100.0f);

    // create deltatime
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
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                resizeView(window, view);
                break;                
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
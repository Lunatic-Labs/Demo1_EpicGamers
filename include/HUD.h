/*
    The HUD controls the onscreen score display, using a custom font.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "../include/DEFINITIONS.h"
#include "../include/Game.h"

namespace EpicGamers
{
    class HUD
    {
    public:
        HUD( GameDataRef data );

        void Draw( );
        void UpdateScore( int score );
        
    private:
        GameDataRef data;

        sf::Text scoreText; 
    };
}
#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h" 
#include <vector>
#include "../include/DEFINITIONS.h"

namespace EpicGamers 
{
    class Hydrant
    {
    public:
        Hydrant( GameDataRef data );

        void SpawnHydrant();
        void MoveHydrants(float dt);
        void DrawHydrants( );
        void RandomiseHydrantOffset();

    private:
        GameDataRef data;
        std::vector<sf::Sprite> hydrantSprites;
    };
}


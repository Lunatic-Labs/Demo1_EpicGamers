#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h" 
#include <vector>
#include "../include/DEFINITIONS.h"

namespace EpicGamers 
{
    class Cat
    {
    public:
        Cat( GameDataRef data );

        void SpawnCat( );
        void SpawnScoringCat( );
        void MoveCats(float dt, float currentSpeed);
        void DrawCats( );
        void RandomiseCatOffset( );

    const std::vector<sf::Sprite> &GetSprites( );
    std::vector<sf::Sprite> &GetScoringSprites();
    private:
        GameDataRef data;
        std::vector<sf::Sprite> catSprites;
        std::vector<sf::Sprite> scoringCats;
    };
}


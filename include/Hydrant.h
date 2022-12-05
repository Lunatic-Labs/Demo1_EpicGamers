/*
    The Hydrant objects function as both the obstacles and the point scoring
    detectors, increasing the score when jumped over.
*/

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

        void SpawnHydrant( );
        void SpawnScoringHydrant( );
        void MoveHydrants(float dt, float currentSpeed);
        void DrawHydrants( );
        void RandomiseHydrantOffset( );

        const std::vector<sf::Sprite>& GetSprites() const;

        std::vector<sf::Sprite> &GetScoringSprites( );
    private:
        GameDataRef data;
        std::vector<sf::Sprite> hydrantSprites;
        std::vector<sf::Sprite> scoringHydrants;
    };
}


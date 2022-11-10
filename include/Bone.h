#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h" 
#include <vector>
#include "../include/DEFINITIONS.h"

namespace EpicGamers 
{
    class Bone
    {
    public:
        Bone( GameDataRef data );

        void SpawnBone( );
        void SpawnScoringBone( );
        void MoveBones(float dt);
        void DrawBones( );
        void RandomiseBoneOffset( );

        std::vector<sf::Sprite> &GetScoringSprites( );
    private:
        GameDataRef data;
        std::vector<sf::Sprite> boneSprites;
        std::vector<sf::Sprite> scoringBones;
    };
}


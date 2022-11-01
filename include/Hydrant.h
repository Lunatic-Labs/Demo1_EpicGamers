#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h" 
#include <vector>

namespace EpicGamers 
{
    class Hydrant
    {
    public:
      Hydrant( GameDataRef data );

      void DrawHydrants( );

    private:
      GameDataRef _data;
      std::vector<sf::Sprite> HydrantSprites;
    };
}


#pragma once
#include <SFML/Graphics.hpp>

namespace EpicGamers
{
	class Collider
	{
	public:
		Collider();
		bool CheckSpriteCollider(sf::Sprite sprite1, sf::Sprite sprite2);
	};
}
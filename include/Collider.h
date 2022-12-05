/*
	The Collider handles the collision detection for sprites.
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace EpicGamers
{
	class Collider
	{
	public:
		Collider();
		//bool CheckSpriteCollider(sf::Sprite sprite1, sf::Sprite sprite2);
		bool CheckSpriteCollider(sf::Sprite sprite1, float scale1 ,sf::Sprite sprite2, float scale2);
	};
}
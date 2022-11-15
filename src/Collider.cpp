#include "../include/Collider.h"

namespace EpicGamers
{
	Collider::Collider()
	{
	}

	bool Collider::CheckSpriteCollider(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
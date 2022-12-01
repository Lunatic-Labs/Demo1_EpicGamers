#include "../include/Ground.h"
#include "../include/DEFINITIONS.h"

namespace EpicGamers
{
	Ground::Ground(GameDataRef data) : data(data)
	{
		sf::Sprite sprite(data->assets.GetTexture("Ground"));
		sf::Sprite sprite2(data->assets.GetTexture("Ground"));
		sprite.setPosition(0, data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getLocalBounds().width, data->window.getSize().y - sprite.getGlobalBounds().height);
		
		groundSprites.push_back(sprite);
		groundSprites.push_back(sprite2);
	}

	void Ground::MoveGround(float dt, float currentSpeed)
	{
		// move the ground sprites and reset their position once they move offscreen
		for (unsigned short int i = 0; i < groundSprites.size(); i++)
		{
			float movement = ((HYDRANT_MOVEMENT_SPEED * dt) + currentSpeed) ;
			groundSprites.at(i).move(-movement, 0.0f);
			if (groundSprites.at(i).getPosition().x < 0 - groundSprites.at(i).getGlobalBounds().width)
			{
				sf::Vector2f position(data->window.getSize().x, groundSprites.at(i).getPosition().y);
				groundSprites.at(i).setPosition(position);
			}
		}
	}
	void Ground::DrawGround()
	{
		for (unsigned short int i = 0; i < groundSprites.size(); i++)
		{
			data->window.draw(groundSprites.at(i));
		}
	}
}
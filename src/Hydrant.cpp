#include "../include/Hydrant.h"
#include <stdlib.h>

namespace EpicGamers
{
	Hydrant::Hydrant(GameDataRef data) : data(data)
	{

	}

	void Hydrant::SpawnHydrant()
	{
		sf::Sprite sprite(data->assets.GetTexture("Hydrant"));
		sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height - 130.0f);
		hydrantSprites.push_back(sprite);
	}

	void Hydrant::SpawnScoringHydrant( )
	{
		sf::Sprite sprite( data->assets.GetTexture( "Scoring Hydrant" ) );

		//sprite.setScale(sprite.getScale().x, data->window.getSize().y);	//Scoring system depends on Scoring collider overlapping with Player collider, so set height to whole window
		sprite.setPosition( data->window.getSize( ).x, 0 );

		scoringHydrants.push_back( sprite );
	}

	void Hydrant::MoveHydrants(float dt, float currentSpeed)
	{
		// handle movement or destruction of the hydrants
		for (unsigned short int i = 0; i < hydrantSprites.size(); i++)
		{
			if (hydrantSprites.at(i).getPosition().x < 0 - hydrantSprites.at(i).getGlobalBounds().width)
			{
				hydrantSprites.erase(hydrantSprites.begin() + i);
			}
			else
			{
				float movement = ((HYDRANT_MOVEMENT_SPEED * dt) + currentSpeed);
				hydrantSprites.at(i).move(-movement, 0);
			}
		}

		// handle movement or destruction of the scoring hydrants
		for (unsigned short int i = 0; i < scoringHydrants.size(); i++)
		{
			if (scoringHydrants.at(i).getPosition().x < 0 - scoringHydrants.at(i).getGlobalBounds().width)
			{
				scoringHydrants.erase(scoringHydrants.begin() + i);
			}
			else
			{
				float movement = ((HYDRANT_MOVEMENT_SPEED * dt) + currentSpeed);
				scoringHydrants.at(i).move(-movement, 0);
			}
		}
		//std::cout << pipeSprites.size() << std::endl;
	}

	void Hydrant::DrawHydrants()
	{
		for (unsigned short int i = 0; i < hydrantSprites.size(); i++)
		{
			this->data->window.draw(hydrantSprites.at(i));
		}
	} 

	const std::vector<sf::Sprite>& Hydrant::GetSprites() const
	{
		return hydrantSprites;
	}

	std::vector<sf::Sprite> &Hydrant::GetScoringSprites( )
	{
		return scoringHydrants; 
	} 
}

#include "../include/Cat.h"
#include <stdlib.h>

namespace EpicGamers
{
	Cat::Cat(GameDataRef data) : data(data)
	{

	}

	void Cat::SpawnCat()
	{
		sf::Sprite sprite(data->assets.GetTexture("Cat"));
		sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height - 130.0f);
		catSprites.push_back(sprite);
	}

	void Cat::SpawnScoringCat( )
	{
		sf::Sprite sprite( data->assets.GetTexture( "Scoring Cat" ) );

		//sprite.setScale(sprite.getScale().x, data->window.getSize().y);	//Scoring system depends on Scoring collider overlapping with Player collider, so set height to whole window
		sprite.setPosition( data->window.getSize( ).x, 0 );

		scoringCats.push_back( sprite );
	}

	void Cat::MoveCats(float dt, float currentSpeed)
	{
		// handle movement or destruction of the cats
		for (unsigned short int i = 0; i < catSprites.size(); i++)
		{
			if (catSprites.at(i).getPosition().x < 0 - catSprites.at(i).getGlobalBounds().width)
			{
				catSprites.erase(catSprites.begin() + i);
			}
			else
			{
				float movement = ((CAT_MOVEMENT_SPEED * dt) + currentSpeed);
				catSprites.at(i).move(-movement, 0);
			}
		}

		// handle movement or destruction of the scoring cats
		for (unsigned short int i = 0; i < scoringCats.size(); i++)
		{
			if (scoringCats.at(i).getPosition().x < 0 - scoringCats.at(i).getGlobalBounds().width)
			{
				scoringCats.erase(scoringCats.begin() + i);
			}
			else
			{
				float movement = ((CAT_MOVEMENT_SPEED * dt) + currentSpeed);
				scoringCats.at(i).move(-movement, 0);
			}
		}
		//std::cout << pipeSprites.size() << std::endl;
	}

	void Cat::DrawCats()
	{
		for (unsigned short int i = 0; i < catSprites.size(); i++)
		{
			this->data->window.draw(catSprites.at(i));
		}
	} 

	const std::vector<sf::Sprite>& Cat::GetSprites()
	{
		return catSprites;
	}

	std::vector<sf::Sprite> & Cat::GetScoringSprites()
	{
		return scoringCats; 
	} 
}

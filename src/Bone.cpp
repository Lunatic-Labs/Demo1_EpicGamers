#include "../include/Bone.h"
#include <stdlib.h>

namespace EpicGamers
{
	Bone::Bone(GameDataRef data) : data(data)
	{
	}

	void Bone::SpawnBone()
	{
		sf::Sprite sprite(data->assets.GetTexture("bone"));
		sprite.setPosition(data->window.getSize().x, data->window.getSize().y - sprite.getGlobalBounds().height - 130.0f);
		boneSprites.push_back(sprite);
	}

	void Bone::SpawnScoringBone( )
	{
		sf::Sprite sprite( data->assets.GetTexture( "Scoring Bone" ) );

		sprite.setPosition( data->window.getSize( ).x, 0 );

		scoringBones.push_back( sprite );
	}

	void Bone::MoveBones(float dt)
	{
		for (unsigned short int i = 0; i < boneSprites.size(); i++)
		{
			if (boneSprites.at(i).getPosition().x < 0 - boneSprites.at(i).getGlobalBounds().width)
			{
				boneSprites.erase(boneSprites.begin() + i);
			}
			else
			{
				float movement = BONE_MOVEMENT_SPEED * dt;
				boneSprites.at(i).move(-movement, 0);
			}
		}

		for (unsigned short int i = 0; i < scoringBones.size(); i++)
		{
			if (scoringBones.at(i).getPosition().x < 0 - scoringBones.at(i).getGlobalBounds().width)
			{
				scoringBones.erase(scoringBones.begin() + i);
			}
			else
			{
				float movement = BONE_MOVEMENT_SPEED * dt;
				scoringBones.at(i).move(-movement, 0);
			}
		}
		//std::cout << pipeSprites.size() << std::endl;
	}

	void Bone::DrawBones()
	{
		for (unsigned short int i = 0; i < boneSprites.size(); i++)
		{
			this->data->window.draw(boneSprites.at(i));
		}
	} 

	std::vector<sf::Sprite> &Bone::GetScoringSprites( )
	{
		return scoringBones; 
	} 
}
#include "../include/AssetManager.h"

#include <sstream>
#include "../include/DEFINITIONS.h"
#include <stdlib.h>

#include <iostream>

namespace EpicGamers
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			this->textures[name] = tex;
		}
	}
	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->textures.at(name);
	}
	
	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->fonts[name] = font;
		}
	}
	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->fonts.at(name);
	}

	void AssetManager::InitAudio() {
		if (!_jumpSoundBuffer.loadFromFile(SFX_JUMP_FILEPATH))
		{
			std::cout << "Error loading jump sound." << std::endl;
		}
		if (!_landSoundBuffer.loadFromFile(SFX_LAND_FILEPATH))
		{
			std::cout << "Error loading land sound." << std::endl;
		}
		if (!_deathSoundBuffer.loadFromFile(SFX_DEATH_FILEPATH))
		{
			std::cout << "Error loading death sound." << std::endl;
		}
		if (!_collectibleSoundBuffer.loadFromFile(SFX_COLLECTIBLE_FILEPATH))
		{
			std::cout << "Error loading collectible sound." << std::endl;
		}

		_jumpSound.setBuffer(_jumpSoundBuffer);
		_landSound.setBuffer(_landSoundBuffer);
		_deathSound.setBuffer(_deathSoundBuffer);
		_collectibleSound.setBuffer(_collectibleSoundBuffer);
	}

	void PlaySound(sf::Sound sound) {
		sound.play();
	}
}
#include "../include/AssetManager.h"

#include <sstream>
#include "../include/DEFINITIONS.h"
#include <stdlib.h>

#include <iostream>

namespace EpicGamers
{
	// textures and fonts
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

	// audio
	void AssetManager::InitAudio() {
		if (!_jumpSoundBuffer.loadFromFile(SFX_JUMP_FILEPATH))
			std::cout << "Error loading jump sound." << std::endl;
		if (!_landSoundBuffer.loadFromFile(SFX_LAND_FILEPATH))
			std::cout << "Error loading land sound." << std::endl;
		if (!_deathSoundBuffer.loadFromFile(SFX_DEATH_FILEPATH))
			std::cout << "Error loading death sound." << std::endl;
		if (!_collectibleSoundBuffer.loadFromFile(SFX_COLLECTIBLE_FILEPATH))
			std::cout << "Error loading collectible sound." << std::endl;

		if (!_levelMusic.openFromFile(LEVEL_MUSIC_FILEPATH))
			std::cout << "Error loading music." << std::endl;

		_jumpSound.setBuffer(_jumpSoundBuffer);
		_landSound.setBuffer(_landSoundBuffer);
		_deathSound.setBuffer(_deathSoundBuffer);
		_collectibleSound.setBuffer(_collectibleSoundBuffer);
	}

	void AssetManager::PlaySound(std::string soundName) {
		if (soundName=="jump")
			_jumpSound.play();
		if (soundName == "death")
			_deathSound.play();
		if (soundName == "land")
			_landSound.play();
		if (soundName == "collectible") {
			_collectibleSound.setVolume(70);
			_collectibleSound.setPitch(2);
			_collectibleSound.play();
		}
			
	}		

	void AssetManager::PlayMusic(std::string musicName) {
		if (musicName == "levelMusic") {
			_levelMusic.setLoop(true);
			_levelMusic.setVolume(70);
			_levelMusic.play();
		}
			
	}

	void AssetManager::StopMusic(std::string musicName) {
		if (musicName == "levelMusic") {
			_levelMusic.stop();
		}

	}
}
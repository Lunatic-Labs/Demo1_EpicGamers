#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace EpicGamers
{
	class AssetManager
	{
	public:
		AssetManager(){}
		~AssetManager(){}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);


	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;

		sf::SoundBuffer _jumpSoundBuffer;
		sf::SoundBuffer _deathSoundBuffer;
		sf::SoundBuffer _landSoundBuffer;
		sf::SoundBuffer _collectibleSoundBuffer;

		sf::Sound _jumpSound;
		sf::Sound _deathSound;
		sf::Sound _landSound;
		sf::Sound _collectibleSound;

		void InitAudio();

		void PlaySound(sf::Sound sound);
	};
}
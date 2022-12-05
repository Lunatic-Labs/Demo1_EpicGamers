/*
	The Input Manager... manages the inputs.
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace EpicGamers
{
	class InputManager
	{
	public:
		InputManager(){}
		~InputManager(){}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}
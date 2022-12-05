/*
	The Splash Screen state activates immediately after running the game. It shows
	a quick screen while assets load, and it then immediately enters the Main Menu
	state.
*/

#pragma once

#include <sstream>
#include "../include/SplashState.h"
#include "../include/MainMenuState.h"
#include "../include/DEFINITIONS.h"

#include <iostream>

namespace EpicGamers
{
	SplashState::SplashState(GameDataRef data) : data(data)
	{

	}

	void SplashState::Init()
	{
		data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		
		background.setTexture(this->data->assets.GetTexture("Splash State Background"));

		data->assets.InitAudio();
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				data->window.close();
			}
		}
	}
	
	void SplashState::Update(float dt)
	{
		if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			//std::cout << "Go to Main Menu" << std::endl;
			data->machine.AddState(StateRef(new MainMenuState(data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		data->window.clear();
		data->window.draw(background);
		data->window.display();
	}
}
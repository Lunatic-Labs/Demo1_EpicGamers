/*
	The Game contains everything inside, well, the game. Gameplay is primarliy
	accomplished by switching between the following Game states: SplashState,
	MainMenuState, GameState, and GameOverState.
*/

#include "../include/Game.h"
#include "../include/SplashState.h"

namespace EpicGamers
{
	Game::Game(int width, int height, std::string title)
	{
		data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		data->machine.AddState(StateRef(new SplashState(this->data)));
		this->Run();
	}

	void Game::Run()
	{
		// create time
		float newTime, frameTime, interpolation;
		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;
		
		// process game states and time
		while (this->data->window.isOpen())
		{
			this->data->machine.ProcessStateChanges();

			newTime = this->clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			
			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->data->machine.GetActiveState()->HandleInput();
				this->data->machine.GetActiveState()->Update(dt);
				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			this->data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}
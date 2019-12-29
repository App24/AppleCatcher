#include "Game.h"
#include "SplashState.h"

#include <stdlib.h>
#include <time.h>

Game::Game(int width, int height, std::string title)
{
	srand(time(NULL));

	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_data->machine.AddState(StateRef(new SplashState(_data)));

	Run();
}

void Game::Run() {
	float newTime, frameTime, interpolation;

	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (_data->window.isOpen()) {
		_data->machine.ProcessStateChanges();

		newTime = _clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f)
			frameTime = 0.25f;
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			sf::Event event;
			while (_data->window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					_data->window.close();
				_data->machine.GetActiveState()->HandleInput(event);
			}
			_data->machine.GetActiveState()->Update(dt);
			accumulator -= dt;
		}

		_data->window.clear();

		interpolation = accumulator / dt;
		_data->machine.GetActiveState()->Draw(interpolation);

		_data->window.display();
	}
}
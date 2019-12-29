#include "SplashState.h"

#include "MenuState.h"

SplashState::SplashState(GameDataRef data):_data(data)
{
}

void SplashState::Init() {
	_data->assets.LoadTexture("Splash State Background", SPLASH_BACKGROUND_FILEPATH);

	_background.setTexture(_data->assets.GetTexture("Splash State Background"));
}

void SplashState::HandleInput(sf::Event event) {
}

void SplashState::Update(float dt) {
	if (_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_TIME)
		_data->machine.AddState(StateRef(new MenuState(_data)));
}

void SplashState::Draw(float dt) {
	_data->window.draw(_background);
}

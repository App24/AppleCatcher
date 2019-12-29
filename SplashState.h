#pragma once
#include "Game.h"
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"

class SplashState : public State
{
public:
	SplashState(GameDataRef data);

	void Init();

	void HandleInput(sf::Event event);

	void Update(float dt);

	void Draw(float dt);
private:
	GameDataRef _data;

	sf::Clock _clock;

	sf::Sprite _background;
};


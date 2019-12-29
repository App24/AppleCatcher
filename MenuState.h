#pragma once
#include "Game.h"
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"

class MenuState : public State
{
public:
	MenuState(GameDataRef data);

	void Init();

	void HandleInput(sf::Event event);

	void Update(float dt);

	void Draw(float dt);
private:
	GameDataRef _data;

	sf::Sprite _playButton, _quitButton;

	sf::Sprite _background;
};


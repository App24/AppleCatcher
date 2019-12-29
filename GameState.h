#pragma once
#include "Game.h"
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "State.h"
#include "Apple.h"
#include "Collision.h"
#include "Player.h"
#include "HUD.h"

class GameState : public State
{
public:
	GameState(GameDataRef data);

	void Init();

	void HandleInput(sf::Event event);

	void Update(float dt);

	void Draw(float dt);
private:
	GameDataRef _data;

	Apple *apple;
	Player *player;
	Collision collision;
	HUD *hud;

	sf::Clock _clock;

	sf::Sprite _background;

	int _score;

	GameStates _state;
};


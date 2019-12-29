#pragma once
#include "Game.h"
#include "DEFINITIONS.h"
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player(GameDataRef data);

	void Move(float dt);

	void Draw();

	sf::Sprite &GetSprite();

private:
	GameDataRef _data;

	sf::Sprite player;
};


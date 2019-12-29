#pragma once
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

class HUD
{
public:
	HUD(GameDataRef data);

	void DrawScore();
	void UpdateScore(int score);
	void DrawStart();

private:
	GameDataRef _data;

	sf::Text _scoreText;
	sf::Text _startText;
};


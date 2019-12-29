#pragma once
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

class Apple
{
public:
	Apple(GameDataRef data);

	void SpawnApple();

	void MoveApples(float dt);

	void DrawApples();

	std::vector<sf::Sprite> &GetSprites();

	void EraseData(int i);
private:
	GameDataRef _data;

	std::vector<sf::Sprite> _apples;
};


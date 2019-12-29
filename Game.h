#pragma once

#include "InputManager.h"
#include "StateMachine.h"
#include "AssetManager.h"
#include <SFML\Graphics.hpp>

#include <memory>
#include <string>

struct GameData
{
	sf::RenderWindow window;
	InputManager input;
	AssetManager assets;
	StateMachine machine;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(int width, int height, std::string title);
private:
	float dt = 1.0f / 60.0f;

	GameDataRef _data = std::make_shared<GameData>();
	sf::Clock _clock;

	void Run();
};


#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include "../UI/uiText.h"
#include "../Entities/player.h"

class GameState : public State {
public:
	void init();

	void handleInput();

	void update();

	void draw();
private:
	sf::Sprite m_background;

	sf::Clock m_spawnClock;

	Player m_player;

	UIText m_scoreText;
};
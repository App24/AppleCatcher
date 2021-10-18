#include "gameState.h"
#include "../Misc/assetManager.h"
#include "../Display/display.h"
#include "../Entities/appleSpawner.h"
#include "../Entities/apple.h"

#define APPLE_SPAWN_FREQUENCY 1.75f

void GameState::init() {
	m_background.setTexture(AssetManager::getTexture("Background"));

	m_scoreText.getText().setString(std::to_string(m_player.getScore()));
}

void GameState::update() {
	if (m_spawnClock.getElapsedTime().asSeconds() > APPLE_SPAWN_FREQUENCY) {
		m_spawnClock.restart();

		AppleSpawner::spawnApple();
	}

	m_player.move();

	AppleSpawner::moveApples();

	std::vector<Apple>& apples = AppleSpawner::getApples();

	for (int i = 0; i < apples.size(); i++) {
		Apple& apple = apples.at(i);

		if (apple.getSprite().getGlobalBounds().intersects(m_player.getSprite().getGlobalBounds())) {
			m_player.increaseScore(apple.getScoreAmount());
			apples.erase(apples.begin() + i);
			m_scoreText.getText().setString(std::to_string(m_player.getScore()));
		}
	}
}

void GameState::draw() {
	Display::getWindow().draw(m_background);
	AppleSpawner::draw();
	m_player.draw();
	m_scoreText.draw();
}

void GameState::handleInput() {

}
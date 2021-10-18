#include "appleSpawner.h"
#include "../Display/display.h"
#include "../Misc/assetManager.h"
#include "../Misc/delta.h"
#include "apple.h"

#define APPLE_MOVEMENT_SPEED 150.0f

std::vector<Apple> AppleSpawner::m_apples;

void AppleSpawner::spawnApple() {
	int scoreAmount = 1;

	if (rand() % 5 == 1) {
		scoreAmount = 5;
	}

	Apple apple(scoreAmount);

	apple.getSprite().setScale(0.5f, 0.5f);

	int spawnRange = Display::getWindow().getSize().x - apple.getSprite().getGlobalBounds().width;

	float spawnX = rand() % spawnRange;

	apple.getSprite().setPosition(spawnX, 0);

	m_apples.push_back(apple);
}

void AppleSpawner::moveApples() {
	for (int i = 0; i < m_apples.size(); i++) {
		Apple& apple = m_apples.at(i);
		apple.getSprite().move(0, APPLE_MOVEMENT_SPEED * Delta::getDelta());
		if (apple.getSprite().getPosition().y > Display::getWindow().getSize().y) {
			m_apples.erase(m_apples.begin() + i);
		}
	}
}

void AppleSpawner::draw() {
	for(auto& apple : m_apples) {
		apple.draw();
	}
}

std::vector<Apple>& AppleSpawner::getApples() {
	return m_apples;
}
#include "apple.h"
#include "../Display/display.h"
#include "../Misc/assetManager.h"

Apple::Apple(int amount) {
	m_amount = amount;

	m_sprite.setTexture(AssetManager::getTexture("Apple"+std::to_string(amount)));
}

void Apple::draw() {
	Display::getWindow().draw(m_sprite);
}

sf::Sprite& Apple::getSprite() {
	return m_sprite;
}

int Apple::getScoreAmount() {
	return m_amount;
}
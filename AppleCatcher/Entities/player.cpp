#include "player.h"
#include "../Display/display.h"
#include "../Misc/assetManager.h"
#include "../Input/keyboard.h"
#include "../Misc/delta.h"

#define PLAYER_MOVEMENT_SPEED 300.0f

Player::Player() {
	m_sprite.setTexture(AssetManager::getTexture("Basket"));

	m_sprite.setPosition((Display::getWindow().getSize().x - m_sprite.getLocalBounds().width) / 2.f, Display::getWindow().getSize().y - m_sprite.getLocalBounds().height * 1.5f);
}

void Player::move() {
	float movement = PLAYER_MOVEMENT_SPEED * Delta::getDelta();
	if (Keyboard::isKeyHeld(sf::Keyboard::A)) {
		m_sprite.move(-movement, 0);
	}
	else if (Keyboard::isKeyHeld(sf::Keyboard::D)) {
		m_sprite.move(movement, 0);
	}

	if (m_sprite.getPosition().x < 0)
		m_sprite.setPosition(0, m_sprite.getPosition().y);
	else if (m_sprite.getPosition().x > Display::getWindow().getSize().x - m_sprite.getLocalBounds().width)
		m_sprite.setPosition(Display::getWindow().getSize().x - m_sprite.getLocalBounds().width, m_sprite.getPosition().y);
}

void Player::draw() {
	Display::getWindow().draw(m_sprite);
}

sf::Sprite& Player::getSprite() {
	return m_sprite;
}

int Player::getScore() {
	return m_score;
}

void Player::increaseScore(int amount) {
	m_score += amount;
}
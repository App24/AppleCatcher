#include "keyboard.h"

bool Keyboard::m_keysPressedThisFrame[sf::Keyboard::KeyCount];
bool Keyboard::m_keysPressed[sf::Keyboard::KeyCount];
bool Keyboard::m_keysHeld[sf::Keyboard::KeyCount];

bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
	if (m_keysPressedThisFrame[key]) return true;

	if (m_keysHeld[key] && !m_keysPressed[key]) {
		m_keysPressed[key] = true;
		m_keysPressedThisFrame[key] = true;
		return true;
	}
	else if (!m_keysHeld[key]) {
		m_keysPressed[key] = false;
	}
	return false;
}

bool Keyboard::isKeyHeld(sf::Keyboard::Key key) {
	return m_keysHeld[key];
}

void Keyboard::resetKeyboard() {
	for (auto& key : m_keysPressedThisFrame) {
		key = false;
	}
}

void Keyboard::onKeyPressed(sf::Event::KeyEvent& event) {
	if (event.code<0 || event.code>sf::Keyboard::KeyCount)
		return;
	m_keysHeld[event.code] = true;
}

void Keyboard::onKeyReleased(sf::Event::KeyEvent& event) {
	if (event.code<0 || event.code>sf::Keyboard::KeyCount)
		return;
	m_keysHeld[event.code] = false;
}
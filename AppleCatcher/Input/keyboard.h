#pragma once

#include <SFML/Graphics.hpp>

class Keyboard {
public:
	static bool isKeyPressed(sf::Keyboard::Key key);
	static bool isKeyHeld(sf::Keyboard::Key key);

	static void onKeyPressed(sf::Event::KeyEvent& event);
	static void onKeyReleased(sf::Event::KeyEvent& event);

	static void resetKeyboard();
private:
	static bool m_keysPressedThisFrame[sf::Keyboard::KeyCount];
	static bool m_keysPressed[sf::Keyboard::KeyCount];
	static bool m_keysHeld[sf::Keyboard::KeyCount];
};
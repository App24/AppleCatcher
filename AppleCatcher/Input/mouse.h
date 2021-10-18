#pragma once

#include <SFML/Graphics.hpp>

class Mouse {
public:
	static bool isButtonPressed(sf::Mouse::Button button);
	static bool isButtonHeld(sf::Mouse::Button button);

	static sf::Vector2i getMousePosition();

	static void onButtonPressed(sf::Event::MouseButtonEvent& event);
	static void onButtonReleased(sf::Event::MouseButtonEvent& event);

	static void onMouseMove(sf::Event::MouseMoveEvent& event);

	static void resetMouse();
private:
	static bool m_buttonsPressedThisFrame[sf::Mouse::ButtonCount];
	static bool m_buttonsPressed[sf::Mouse::ButtonCount];
	static bool m_buttonsHeld[sf::Mouse::ButtonCount];

	static sf::Vector2i m_mousePosition;
};
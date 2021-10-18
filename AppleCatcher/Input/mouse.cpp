#include "mouse.h"

bool Mouse::m_buttonsPressedThisFrame[sf::Mouse::ButtonCount];
bool Mouse::m_buttonsPressed[sf::Mouse::ButtonCount];
bool Mouse::m_buttonsHeld[sf::Mouse::ButtonCount];

sf::Vector2i Mouse::m_mousePosition;

bool Mouse::isButtonPressed(sf::Mouse::Button button) {
	if (m_buttonsPressedThisFrame[button]) return true;

	if (m_buttonsHeld[button] && !m_buttonsPressed[button]) {
		m_buttonsPressed[button] = true;
		m_buttonsPressedThisFrame[button] = true;
		return true;
	}
	else if (!m_buttonsHeld[button]) {
		m_buttonsPressed[button] = false;
	}
	return false;
}

bool Mouse::isButtonHeld(sf::Mouse::Button button) {
	return m_buttonsHeld[button];
}

sf::Vector2i Mouse::getMousePosition() {
	return m_mousePosition;
}

void Mouse::resetMouse() {
	for (auto& button : m_buttonsPressedThisFrame) {
		button = false;
	}
}

void Mouse::onButtonPressed(sf::Event::MouseButtonEvent& event) {
	if (event.button<0 || event.button>sf::Mouse::ButtonCount)
		return;
	m_buttonsHeld[event.button] = true;
}

void Mouse::onButtonReleased(sf::Event::MouseButtonEvent& event) {
	if (event.button<0 || event.button>sf::Mouse::ButtonCount)
		return;
	m_buttonsHeld[event.button] = false;
}

void Mouse::onMouseMove(sf::Event::MouseMoveEvent& event) {
	m_mousePosition = sf::Vector2i(event.x, event.y);
}
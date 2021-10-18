#include "display.h"
#include "../Input/keyboard.h"
#include "../Input/mouse.h"

sf::RenderWindow Display::m_window;

void Display::create(unsigned int width, unsigned int height, const char* title) {
	m_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	m_window.setVerticalSyncEnabled(true);
}

bool Display::isOpen() {
	return m_window.isOpen();
}

void Display::pollEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			Keyboard::onKeyPressed(event.key);
			break;
		case sf::Event::KeyReleased:
			Keyboard::onKeyReleased(event.key);
			break;
		case sf::Event::MouseButtonPressed:
			Mouse::onButtonPressed(event.mouseButton);
			break;
		case sf::Event::MouseButtonReleased:
			Mouse::onButtonReleased(event.mouseButton);
			break;
		case sf::Event::MouseMoved:
			Mouse::onMouseMove(event.mouseMove);
			break;
		}
	}
}

sf::RenderWindow& Display::getWindow() {
	return m_window;
}
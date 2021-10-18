#pragma once

#include <SFML/Graphics.hpp>

class Display {
public:
	static void create(unsigned int width, unsigned int height, const char* title);

	static bool isOpen();

	static void pollEvents();

	static sf::RenderWindow& getWindow();
private:
	static sf::RenderWindow m_window;
};
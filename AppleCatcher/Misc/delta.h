#pragma once

#include <SFML/Graphics.hpp>

class Delta {
public:
	static void updateDelta();

	static float getDelta();
private:
	static sf::Clock m_deltaClock;

	static float m_delta;
};
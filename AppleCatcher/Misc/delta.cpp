#include "delta.h"

sf::Clock Delta::m_deltaClock;
float Delta::m_delta;

void Delta::updateDelta() {
	m_delta = m_deltaClock.restart().asSeconds();
}

float Delta::getDelta() {
	return m_delta;
}
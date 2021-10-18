#pragma once

#include <SFML/Graphics.hpp>

class Apple {
public:
	Apple(int amount);

	void draw();

	sf::Sprite& getSprite();

	int getScoreAmount();
private:
	sf::Sprite m_sprite;

	int m_amount;
};
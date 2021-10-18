#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player();

	void move();

	void draw();

	sf::Sprite& getSprite();

	int getScore();

	void increaseScore(int amount = 1);
private:
	sf::Sprite m_sprite;

	int m_score;
};
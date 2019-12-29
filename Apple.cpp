#include "Apple.h"

#include <iostream>

Apple::Apple(GameDataRef data):_data(data)
{
}

void Apple::SpawnApple() {
	sf::Sprite sprite(_data->assets.GetTexture("Apple"));

	sprite.setScale(sf::Vector2f(0.5f, 0.5f));

	int spawnPlace = _data->window.getSize().x - sprite.getGlobalBounds().width;

	float spawnX = rand() % (spawnPlace);

	sprite.setPosition(spawnX, 0);

	_apples.push_back(sprite);
}

void Apple::MoveApples(float dt) {
	for (unsigned short int i = 0; i < _apples.size(); i++) {
		if (_apples.at(i).getPosition().y > _data->window.getSize().y) {
			_apples.erase(_apples.begin() + i);
		}
		else {
			float movement = APPLE_MOVEMENT_SPEED * dt;

			_apples.at(i).move(0, movement);
		}
	}
}

void Apple::DrawApples() {
	for (unsigned short int i = 0; i < _apples.size(); i++) {
		_data->window.draw(_apples.at(i));
	}
}

std::vector<sf::Sprite> &Apple::GetSprites() {
	return _apples;
}

void Apple::EraseData(int i) {
	_apples.erase(_apples.begin() + i);
}
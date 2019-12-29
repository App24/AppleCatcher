#include "Player.h"



Player::Player(GameDataRef data):_data(data)
{
	player.setTexture(_data->assets.GetTexture("Player"));

	player.setPosition(_data->window.getSize().x / 2 - player.getGlobalBounds().width / 2, _data->window.getSize().y - player.getGlobalBounds().height *1.5);

}

void Player::Move(float dt) {
	float movement = PLAYER_MOVEMENT_SPEED * dt;
	if (_data->input.IsKeyHeld(sf::Keyboard::A))
		player.move(-movement, 0);
	if (_data->input.IsKeyHeld(sf::Keyboard::D))
		player.move(movement, 0);

	if (player.getPosition().x > _data->window.getSize().x - player.getGlobalBounds().width)
		player.setPosition(_data->window.getSize().x - player.getGlobalBounds().width, player.getPosition().y);
	if (player.getPosition().x < 0)
		player.setPosition(0, player.getPosition().y);
}

void Player::Draw() {
	_data->window.draw(player);
}

sf::Sprite &Player::GetSprite() {
	return player;
}
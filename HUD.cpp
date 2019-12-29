#include "HUD.h"
#include <string>


HUD::HUD(GameDataRef data) :_data(data)
{
	_scoreText.setFont(_data->assets.GetFont("Flappy Font"));

	_scoreText.setString("0");

	_scoreText.setCharacterSize(36);

	_scoreText.setFillColor(sf::Color::Red);

	//_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

	_scoreText.setPosition(10, 0);

	_startText.setFont(_data->assets.GetFont("Arial Font"));

	_startText.setString("Click to start\n   the game");

	_startText.setCharacterSize(64);

	_startText.setFillColor(sf::Color::Green);

	//_startText.setOrigin(_startText.getGlobalBounds().width / 2, _startText.getGlobalBounds().height / 2);

	_startText.setPosition(_data->window.getSize().x/2- _startText.getGlobalBounds().width / 2, _data->window.getSize().y / 2 - _startText.getGlobalBounds().height / 2);
}

void HUD::DrawScore() {
	_data->window.draw(_scoreText);
}

void HUD::DrawStart() {
	_data->window.draw(_startText);
}

void HUD::UpdateScore(int score) {
	_scoreText.setString(std::to_string(score));
}

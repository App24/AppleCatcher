#include "GameState.h"

#include <iostream>

GameState::GameState(GameDataRef data) :_data(data)
{
}

void GameState::Init() {
	_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Apple", APPLE_FILEPATH);
	_data->assets.LoadTexture("Player", PLAYER_FILEPATH);
	_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
	_data->assets.LoadFont("Arial Font", ARIAL_FONT_FILEPATH);

	apple = new Apple(_data);
	player = new Player(_data);
	hud = new HUD(_data);

	_score = 0;

	_background.setTexture(_data->assets.GetTexture("Game Background"));

	_state = GameStates::eReady;
}

void GameState::HandleInput(sf::Event event) {
	if (_state == GameStates::eReady) {
		if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
			_state = GameStates::ePlay;
		}
	}
}

void GameState::Update(float dt) {
	if (_state == GameStates::ePlay) {
		apple->MoveApples(dt);
		player->Move(dt);

		if (_clock.getElapsedTime().asSeconds() > APPLE_SPAWN_FREQUENCY) {
			apple->SpawnApple();
			_clock.restart();
		}

		std::vector<sf::Sprite> sprites = apple->GetSprites();

		for (unsigned int i = 0; i < sprites.size(); i++)
		{
			if (collision.CheckTopSpriteCollision(sprites.at(i), player->GetSprite())) {
				apple->EraseData(i);
				_score += 1;
				hud->UpdateScore(_score);
			}
		}
	}
	
}

void GameState::Draw(float dt) {
	_data->window.draw(_background);
	apple->DrawApples();
	player->Draw();
	hud->DrawScore();
	if (_state == GameStates::eReady) {
		hud->DrawStart();
	}
}

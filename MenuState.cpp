#include "MenuState.h"

#include "GameState.h"

MenuState::MenuState(GameDataRef data) :_data(data)
{
}

void MenuState::Init() {
	_data->assets.LoadTexture("Menu Background", MENU_BACKGROUND_FILEPATH);
	_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
	_data->assets.LoadTexture("Quit Button", QUIT_BUTTON_FILEPATH);

	_background.setTexture(_data->assets.GetTexture("Menu Background"));

	_playButton.setTexture(_data->assets.GetTexture("Play Button"));
	_quitButton.setTexture(_data->assets.GetTexture("Quit Button"));

	_playButton.setPosition(_data->window.getSize().x / 2 - _playButton.getGlobalBounds().width / 2, _data->window.getSize().y / 3);
	_quitButton.setPosition(_data->window.getSize().x / 2 - _quitButton.getGlobalBounds().width / 2, _data->window.getSize().y / 2 + _quitButton.getGlobalBounds().height / 2);
}

void MenuState::HandleInput(sf::Event event) {
	if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
		_data->machine.AddState(StateRef(new GameState(_data)));
	}

	if (_data->input.IsSpriteClicked(_quitButton, sf::Mouse::Left, _data->window)) {
		_data->window.close();
	}
}

void MenuState::Update(float dt) {
}

void MenuState::Draw(float dt) {
	_data->window.draw(_background);
	_data->window.draw(_playButton);
	_data->window.draw(_quitButton);
}

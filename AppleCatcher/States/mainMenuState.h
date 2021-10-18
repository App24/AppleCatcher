#pragma once
#include "state.h"
#include "../UI/uiText.h"
#include "../UI/uiButton.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public State {
public:
	void init();

	void draw();

	void update();
	
	void handleInput();
private:
	sf::Sprite m_backgroundSprite;

	UIText m_titleText;

	UIButton m_playButton, m_quitButton;
};
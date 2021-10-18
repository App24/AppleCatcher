#include "mainMenuState.h"
#include "../Display/display.h"
#include "../Misc/assetManager.h"
#include "stateMachine.h"
#include "gameState.h"

void MainMenuState::init() {
	m_backgroundSprite.setTexture(AssetManager::getTexture("Background"));

	m_titleText.getText().setString("AppleCatcher");
	m_titleText.getText().setFillColor(sf::Color::Black);
	m_titleText.getText().setCharacterSize(50);
	m_titleText.getText().setPosition(sf::Vector2f((Display::getWindow().getSize().x - m_titleText.getText().getLocalBounds().width) / 2.f, Display::getWindow().getSize().y / 4.f));

	float middleScreen = (Display::getWindow().getSize().x - m_playButton.getButtonSprite().getLocalBounds().width) / 2.f;

	m_playButton.getButtonText().setString("Play");
	m_playButton.getButtonSprite().setPosition(sf::Vector2f(middleScreen, Display::getWindow().getSize().y / 3.f));

	m_quitButton.getButtonText().setString("Quit");
	m_quitButton.getButtonSprite().setPosition(sf::Vector2f(middleScreen, Display::getWindow().getSize().y / 2.f));
}

void MainMenuState::draw() {
	Display::getWindow().draw(m_backgroundSprite);
	m_titleText.draw();
	m_playButton.draw();
	m_quitButton.draw();
}

void MainMenuState::update() {
	if (m_playButton.isClicked()) {
		StateMachine::addState(StateRef(new GameState()));
	}

	if (m_quitButton.isClicked()) {
		Display::getWindow().close();
	}
}

void MainMenuState::handleInput() {

}
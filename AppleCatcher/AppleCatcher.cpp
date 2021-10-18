#include <iostream>
#include <SFML/Graphics.hpp>
#include "Display/display.h"
#include "States/stateMachine.h"
#include "States/mainMenuState.h"
#include "Input/keyboard.h"
#include "Input/mouse.h"
#include "Misc/delta.h"
#include "Misc/assetLoader.hpp"

int main()
{
	Display::create(1280, 720, "AppleCatcher");

	loadAssets();

	StateMachine::addState(StateRef(new MainMenuState()));

	while (Display::isOpen()) {
		Display::pollEvents();
		Delta::updateDelta();
		StateMachine::processStateChanges();

		Display::getWindow().clear();
		if (!StateMachine::empty()) {
			StateMachine::getActiveState()->handleInput();
			StateMachine::getActiveState()->update();
			StateMachine::getActiveState()->draw();
		}
		Display::getWindow().display();

		Keyboard::resetKeyboard();
		Mouse::resetMouse();
	}

	return 0;
}

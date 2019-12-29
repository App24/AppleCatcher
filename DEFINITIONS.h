#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SPLASH_BACKGROUND_FILEPATH "Resources/res/splashBackground.png"

#define MENU_BACKGROUND_FILEPATH "Resources/res/menuBackground.png"

#define GAME_BACKGROUND_FILEPATH "Resources/res/gameBackground.png"
#define APPLE_FILEPATH "Resources/res/apple.png"
#define PLAYER_FILEPATH "Resources/res/player.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"
#define ARIAL_FONT_FILEPATH "Resources/fonts/arial.ttf"

#define PLAY_BUTTON_FILEPATH "Resources/res/playButton.png"
#define QUIT_BUTTON_FILEPATH "Resources/res/quitButton.png"

#define SPLASH_SCREEN_TIME 3.0f
#define APPLE_MOVEMENT_SPEED 150.0f
#define PLAYER_MOVEMENT_SPEED 300.0f

#define APPLE_SPAWN_FREQUENCY 1.75f

enum GameStates {
	eReady,
	ePlay
};
#pragma once
#include "assetManager.h"

void loadAssets() {
	AssetManager::loadTexture("Background", "Assets/textures/background.png");
	AssetManager::loadTexture("Apple1", "Assets/textures/apple.png");
	AssetManager::loadTexture("Apple5", "Assets/textures/goldenApple.png");
	AssetManager::loadTexture("Basket", "Assets/textures/basket.png");
	AssetManager::loadTexture("Button", "Assets/textures/button.png");

	AssetManager::loadFont("Arial", "Assets/fonts/arial.ttf");
}
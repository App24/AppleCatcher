#include "AssetManager.h"

void AssetManager::LoadTexture(std::string name, std::string fileName) {
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
		_textures[name] = tex;
}

void AssetManager::LoadFont(std::string name, std::string fileName) {
	sf::Font font;

	if (font.loadFromFile(fileName))
		_fonts[name] = font;
}

sf::Texture &AssetManager::GetTexture(std::string name) {
	return _textures.at(name);
}

sf::Font &AssetManager::GetFont(std::string name) {
	return _fonts.at(name);
}
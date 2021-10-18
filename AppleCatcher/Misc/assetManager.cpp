#include "assetManager.h"

std::map<std::string, sf::Texture> AssetManager::m_textures;
std::map<std::string, sf::Font> AssetManager::m_fonts;

void AssetManager::loadTexture(std::string name, std::string filepath) {
	sf::Texture texture;

	if (texture.loadFromFile(filepath))
		m_textures[name] = texture;
}

void AssetManager::loadFont(std::string name, std::string filepath) {
	sf::Font font;

	if (font.loadFromFile(filepath))
		m_fonts[name] = font;
}

sf::Texture& AssetManager::getTexture(std::string name) {
	return m_textures.at(name);
}

sf::Font& AssetManager::getFont(std::string name) {
	return m_fonts.at(name);
}
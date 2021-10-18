#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager {
public:
	static void loadTexture(std::string name, std::string filepath);
	static void loadFont(std::string name, std::string filepath);

	static sf::Texture& getTexture(std::string name);
	static sf::Font& getFont(std::string name);
private:
	static std::map<std::string, sf::Texture> m_textures;
	static std::map<std::string, sf::Font> m_fonts;
};
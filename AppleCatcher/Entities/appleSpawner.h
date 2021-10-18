#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Apple;

class AppleSpawner {
public:
	static void spawnApple();

	static void moveApples();

	static void draw();

	static std::vector<Apple>& getApples();
private:
	static std::vector<Apple> m_apples;
};
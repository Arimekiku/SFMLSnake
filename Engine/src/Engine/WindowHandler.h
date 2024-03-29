#pragma once

#include <SFML\Graphics.hpp>

namespace engine {
	class WindowHandler {
	public:
		WindowHandler(sf::RenderWindow* newWindow);
		~WindowHandler() = default;

		void render();
		void close();
		void addRenderable(sf::Sprite* newObject);
		void removeRenderable(sf::Sprite* objectToRemove);

	private:
		sf::RenderWindow* window;

		std::vector<sf::Sprite*> renderObjects;
	};
}
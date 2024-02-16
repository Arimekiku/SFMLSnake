#pragma once

#include "Services/TextureAtlas.h"

namespace engine {
	class WindowHandler {
	public:
		WindowHandler();
		virtual ~WindowHandler();

		void render();
		void addRenderable(sf::Sprite* newObject);

	private:
		sf::RenderWindow* window;

		std::vector<sf::Sprite*> renderObjects;
	};
}
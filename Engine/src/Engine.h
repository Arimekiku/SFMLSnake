#pragma once

#include "Engine/WindowHandler.h"
#include "Engine/EventHandler.h"
#include "Engine/Entities/Player.h"
#include "Engine/Services/TextureAtlas.h"

namespace engine {
	class Engine {
	public:
		Engine();
		~Engine();

		void update();

	private:
		void close();
		bool isOpen();

		WindowHandler* windowHandler;
		EventHandler* eventHandler;

		TextureAtlas* textureAtlas;
		Player* player;

		sf::RenderWindow* window;
	};
}
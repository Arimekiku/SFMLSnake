#pragma once

#include "Engine/WindowHandler.h"
#include "Engine/EventHandler.h"
#include "Engine/Entities/Player.h"
#include "Engine/Services/TextureAtlas.h"
#include "Engine/Services/GameObjectFactory.h"

namespace engine {
	class Engine {
	public:
		Engine();
		~Engine();

		void update();

	private:
		void close();
		bool isOpen();

		GameObjectFactory* objFactory;
		WindowHandler* windowHandler;
		EventHandler* eventHandler;

		Player* player;

		sf::RenderWindow* window;
	};
}
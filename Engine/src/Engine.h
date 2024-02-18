#pragma once

#include "Engine/WindowHandler.h"
#include "Engine/EventHandler.h"
#include "Engine/PlayerHandler.h"

namespace engine {
	class Engine {
	public:
		Engine();
		~Engine();

		void update();

	private:
		Field* field;

		WindowHandler* windowHandler;
		EventHandler* eventHandler;
		PlayerHandler* playerHandler;

		sf::RenderWindow* window;
	};
}
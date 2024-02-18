#pragma once

#include "PlayerHandler.h"

#include <SFML\Graphics.hpp>

namespace engine {
	class EventHandler {
	public:
		EventHandler(sf::RenderWindow* newWindow, PlayerHandler* newPlayer);
		~EventHandler() = default;

		void pollEvents();

	private:
		sf::RenderWindow* window;
		PlayerHandler* player;
	};
}
#pragma once

#include <SFML\Graphics.hpp>

namespace engine {
	class EventHandler {
	public:
		EventHandler(sf::RenderWindow* newWindow);
		~EventHandler() = default;

		std::vector<sf::Event> pollEvents();

	private:
		sf::RenderWindow* window;
	};
}
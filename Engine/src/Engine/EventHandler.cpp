#include "EventHandler.h"

namespace engine {
	EventHandler::EventHandler(sf::RenderWindow* newWindow) {
		window = newWindow;
	}

	std::vector<sf::Event> EventHandler::pollEvents() {
		std::vector<sf::Event> events;

		sf::Event e;
		while (window->pollEvent(e)) {
			sf::Event newEvent = sf::Event(e);

			events.push_back(newEvent);
		}

		return events;
	}
}
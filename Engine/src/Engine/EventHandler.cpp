#include "EventHandler.h"

namespace engine {
    EventHandler::EventHandler(sf::RenderWindow* newWindow, PlayerHandler* newPlayer) {
        window = newWindow;
        player = newPlayer;
    }

    void EventHandler::pollEvents() {
        sf::Event e;
        while (window->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window->close();
            }

            if (e.type == sf::Event::KeyPressed) {
                switch (e.key.scancode) {
                case sf::Keyboard::Key::W:
                    player->setMovementVector(sf::Vector2i(0, -1));
                    break;
                case sf::Keyboard::Key::S:
                    player->setMovementVector(sf::Vector2i(0, 1));
                    break;
                case sf::Keyboard::Key::A:
                    player->setMovementVector(sf::Vector2i(-1, 0));
                    break;
                case sf::Keyboard::Key::D:
                    player->setMovementVector(sf::Vector2i(1, 0));
                    break;
                case sf::Keyboard::Key::Escape:
                    window->close();
                    break;
                }
            }
        }
    }
}
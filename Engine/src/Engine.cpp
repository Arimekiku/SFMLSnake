#include "Engine.h"

#include <iostream>
#include <functional>
#include "Engine/Services/Timer.h"

namespace engine {
	Engine::Engine() {
        window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
        if (window == NULL) {
            std::cout << "Can't create the window!" << std::endl;
            throw std::exception();
        }
        window->setFramerateLimit(60);

        windowHandler = new WindowHandler(window);

        field = new Field(20, 15, windowHandler);
        std::vector<Tile*> tiles = field->generateField();

        for (const auto& tile : tiles) {
            if (tile->getType() == SNAKE) {
                playerHandler = new PlayerHandler(field, tile);
                playerHandler->addSegment();
                playerHandler->addSegment();
            }
        }
        field->spawnNextAppleTile();

        eventHandler = new EventHandler(window, playerHandler);
	}

    Engine::~Engine() {
        delete windowHandler;
        delete eventHandler;
        delete playerHandler;

        delete window;
    }

    void Engine::update() {
        sf::Clock cl;

        Timer t = Timer(0.5);
        t.bind(std::bind(&PlayerHandler::movePlayer, playerHandler));

        while (window->isOpen()) {
            float deltaTime = cl.restart().asSeconds();
            t.tick(deltaTime);

            field->update();
            eventHandler->pollEvents();
            windowHandler->render();
        }
    }
}
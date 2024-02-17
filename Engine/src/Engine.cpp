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
        eventHandler = new EventHandler(window);

        objFactory = new GameObjectFactory();

        GameObject* testObj1 = objFactory->spawnObject(GameObjectType::SNAKE_SEGMENT);
        testObj1->setPosition(sf::Vector2i(10, 8));

        GameObject* testObj2 = objFactory->spawnObject(GameObjectType::SNAKE_SEGMENT);
        testObj2->setPosition(sf::Vector2i(10, 7));

        GameObject* testObj3 = objFactory->spawnObject(GameObjectType::SNAKE_SEGMENT);
        testObj3->setPosition(sf::Vector2i(10, 6));

        player = new Player(testObj1);
        windowHandler->addRenderable(testObj1->sprite);
        player->addSegment(testObj2);
        windowHandler->addRenderable(testObj2->sprite);
        player->addSegment(testObj3);
        windowHandler->addRenderable(testObj3->sprite);
	}

    Engine::~Engine() {
        delete windowHandler;
        delete eventHandler;

        delete window;
    }

    void Engine::update() {
        sf::Clock cl;

        Timer* t = new Timer(2);
        t->bind(std::bind(&Player::move, player));

        while (isOpen()) {
            float deltaTime = cl.restart().asSeconds();

            std::vector<sf::Event> events = eventHandler->pollEvents();

            for (const auto& e : events) {
                if (e.type == sf::Event::Closed) {
                    close();
                }

                if (e.type == sf::Event::KeyPressed) {
                    switch (e.key.scancode) {
                        case sf::Keyboard::Key::W:
                            player->setMovementVector({ 0, -1 });
                            break;
                        case sf::Keyboard::Key::S: 
                            player->setMovementVector({ 0, 1 });
                            break;
                        case sf::Keyboard::Key::A:
                            player->setMovementVector({ -1, 0 });
                            break;
                        case sf::Keyboard::Key::D:
                            player->setMovementVector({ 1, 0 });
                            break;
                    }
                }
            }

            t->tick(deltaTime);

            windowHandler->render();
        }
    }

    void Engine::close() {
        window->close();

        delete this;
    }

    bool Engine::isOpen() {
        if (window->isOpen()) {
            return true;
        }

        return false;
    }
}
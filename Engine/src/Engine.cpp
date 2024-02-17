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

        textureAtlas = new TextureAtlas();
        textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");

        player = new Player({ 320, 240 }, textureAtlas->getTexture("BRICK"));
        windowHandler->addRenderable(player->sprite);
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

            t->tick(cl.restart().asSeconds());

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
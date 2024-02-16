#include "WindowHandler.h"

#include <iostream>
#include "Entities/Wall.h"

namespace engine {
    WindowHandler::WindowHandler() {
        window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
        if (window == NULL) {
            std::cout << "Can't create the window!" << std::endl;
            throw std::exception();
        }
    }

    WindowHandler::~WindowHandler() {
        delete window;
    }

    void WindowHandler::render()
    {
        window->clear();

        for (auto obj : renderObjects) {
            window->draw(*obj);
        }

        window->display();
    }

    void WindowHandler::addRenderable(sf::Sprite* newObject) {
        renderObjects.push_back(newObject);
    }
}
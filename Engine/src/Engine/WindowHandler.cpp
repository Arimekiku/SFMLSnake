#include "WindowHandler.h"

#include <iostream>

namespace engine {
    WindowHandler::WindowHandler(sf::RenderWindow* newWindow) {
        window = newWindow;
    }

    void WindowHandler::render() {
        window->clear();

        for (auto obj : renderObjects) {
            window->draw(*obj);
        }

        window->display();
    }

    void WindowHandler::close() {
        window->close();
    }

    void WindowHandler::addRenderable(sf::Sprite* newObject) {
        renderObjects.push_back(newObject);
    }

    void WindowHandler::removeRenderable(sf::Sprite* objectToRemove) {
        auto e = std::find(renderObjects.begin(), renderObjects.end(), objectToRemove);

        if (e != renderObjects.end()) {
            renderObjects.erase(e);
        }
    }
}
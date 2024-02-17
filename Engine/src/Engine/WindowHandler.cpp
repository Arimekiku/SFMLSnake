#include "WindowHandler.h"

#include <iostream>

namespace engine {
    WindowHandler::WindowHandler(sf::RenderWindow* newWindow) {
        window = newWindow;
    }

    WindowHandler::~WindowHandler() {
        for (auto obj : renderObjects) {
            delete obj;
        }
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

    void WindowHandler::removeRenderable(sf::Sprite* objectToRemove) {
        auto e = std::find(renderObjects.begin(), renderObjects.end(), objectToRemove);

        if (e != renderObjects.end()) {
            renderObjects.erase(e);
        }
    }
}
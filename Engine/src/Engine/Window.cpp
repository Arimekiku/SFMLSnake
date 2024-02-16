#include "Window.h"

#include <iostream>
#include "GameObject/Wall.h"

namespace engine {
    Window::Window() {
        textureAtlas = new TextureAtlas();
        textureAtlas->addTexture("WALL", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");

        for (int i = 0; i < 10; i++) {
            auto newObject = new Wall({ i * 32, 0 }, textureAtlas->getTexture("WALL"));
            addGameObject(newObject);
        }
    }

    Window::~Window() {
        delete textureAtlas;
    }

    void Window::run() {
        auto window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
        if (window == NULL) {
            std::cout << "Can't create the window!" << std::endl;
            throw std::exception();
        }

        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear();

            for (auto obj : objects) {
                window->draw(obj->sprite);
            }

            window->display();
        }

        delete window;
    }

    void Window::addGameObject(GameObject* newObject) {
        objects.push_back(newObject);
    }
}
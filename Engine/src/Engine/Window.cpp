#include "Window.h"

#include <iostream>

namespace engine {
    Window::Window() {
        textureAtlas = new TextureAtlas();
        textureAtlas->addTexture("APPLE", R"(D:\Dev\C++\SFMLSnake\resources\apple.png)");
    }

    Window::~Window() {
        delete textureAtlas;
    }

    void Window::Run() {
        auto window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!");
        if (window == NULL) {
            std::cout << "Can't create the window!" << std::endl;
            throw std::exception();
        }

        sf::Sprite* testSprite = new sf::Sprite(*textureAtlas->getTexture("APPLE"));

        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear();

            window->draw(*testSprite);

            window->display();
        }

        delete window;
    }
}
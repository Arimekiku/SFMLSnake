#include "Window.h"

#include <iostream>
#include <SFML/Graphics.hpp>

namespace engine {
    Window::Window() {

    }

    Window::~Window() {

    }

    void Window::Run() {
        auto window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");

        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            window->clear();

            window->display();
        }
    }
}
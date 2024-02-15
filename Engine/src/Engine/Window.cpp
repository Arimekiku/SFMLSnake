#include "Window.h"

#include <iostream>
#include <SFML/Graphics.hpp>

namespace engine {
    Window::Window() {

    }

    Window::~Window() {

    }

    void Window::Run() {
        auto window = sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
        auto shape = sf::CircleShape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            window.draw(shape);

            window.display();
        }
    }
}
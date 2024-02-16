#pragma once

#include <SFML/Graphics.hpp>

namespace engine {
	class GameObject {
	public:
		virtual ~GameObject() = default;

		virtual void update() = 0;

		sf::Vector2i worldPos;
		sf::Sprite sprite;

	protected:
		GameObject() = default;
	};
}
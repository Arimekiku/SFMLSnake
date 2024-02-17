#pragma once

#include <SFML/Graphics.hpp>

namespace engine {
	class GameObject {
	public:
		GameObject(const sf::Vector2i initPos, const sf::Texture* texture);
		virtual ~GameObject() = default;

		virtual void update() = 0;

		sf::Sprite* sprite;

	protected:
		sf::Vector2i worldPos;
	};
}
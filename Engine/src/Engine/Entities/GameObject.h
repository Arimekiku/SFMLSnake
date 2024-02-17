#pragma once

#include <SFML/Graphics.hpp>

namespace engine {
	class GameObject {
	public:
		GameObject(const sf::Texture* texture);
		virtual ~GameObject() = default;

		sf::Vector2i getPosition() const;
		void setPosition(const sf::Vector2i& newPosition);

		sf::Sprite* sprite;

	private:
		sf::Vector2i worldPos;
		sf::Vector2u textureSize;
	};
}
#pragma once

#include "GameObject.h"

namespace engine {
	class Wall : public GameObject {
	public:
		Wall(const sf::Texture* texture);
		~Wall();
	};
}
#pragma once

#include "../GameObject.h"

class Wall : public GameObject {
public:
	Wall(const sf::Vector2i initPos, const sf::Texture* texture);
	~Wall();

	void update() override;
};
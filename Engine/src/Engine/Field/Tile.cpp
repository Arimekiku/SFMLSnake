#include "Tile.h"

namespace engine {
	Tile::Tile(TileType newType, GameObject* newObject)
	{
		type = newType;
		object = newObject;
	}

	TileType Tile::getType()
	{
		return type;
	}

	GameObject* Tile::getObject()
	{
		return object;
	}
}
#pragma once

#include "Services/TextureAtlas.h"
#include "Services/Timer.h"
#include "GameObject.h"

namespace engine {
	class Window {
	public:
		Window();
		virtual ~Window();

		void run();
		void addGameObject(GameObject* newObject);

		Timer testTimer { 2 };

	private:
		TextureAtlas* textureAtlas;

		std::vector<GameObject*> objects;
	};
}
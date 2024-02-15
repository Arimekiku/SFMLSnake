#pragma once

#include "Services/TextureAtlas.h"

namespace engine {
	class Window {
	public:
		Window();
		virtual ~Window();

		void Run();

	private:
		TextureAtlas* textureAtlas;
	};
}
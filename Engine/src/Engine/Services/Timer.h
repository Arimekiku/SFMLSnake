#pragma once

#include<functional>

namespace engine {
	class Timer {
	public:
		Timer(float timeout);

		void tick(float deltaTime);
		void reset();
		void bind(std::function<void()> func);

	private:
		std::function<void()> func;

		float target;
		float secondsElapsed;
	};
}
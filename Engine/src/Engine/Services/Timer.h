#pragma once

namespace engine {
	class Timer {
	public:
		Timer(float timeout);

		void tick(float deltaTime);
		void reset();
		void bind(void (*func)());

	private:
		void (*func)();

		float target;
		float secondsElapsed;
	};
}
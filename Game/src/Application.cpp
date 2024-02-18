#include "Engine.h"
#include <iostream>

class Application : public engine::Engine {
public:
	Application() { }
	~Application() { }
};

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Application* app = new Application(); 
	app->update();

	return 0;
}
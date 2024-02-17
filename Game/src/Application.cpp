#include "Engine.h"
#include <iostream>

class Application : public engine::Engine {
public:
	Application() { }
	~Application() { }
};

int main() {
	Application* app = new Application(); 

	app->update();

	return 0;
}
#include "Engine.h"

class Application : public engine::Window {
public:
	Application() { }
	~Application() { }
};

int main() {
	Application* app = new Application(); 
	app->Run();

	delete app;
		
	return 0;
}
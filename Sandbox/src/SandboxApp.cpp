#include <Rambutan.h>

class Sandbox : public Rambutan::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Rambutan::Application* Rambutan::CreateApplication()
{
	return new Sandbox();
}
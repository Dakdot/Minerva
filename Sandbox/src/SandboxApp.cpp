#include <Rambutan.h>

class ExampleLayer : public Rambutan::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		RB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rambutan::Event& event) override
	{
		RB_TRACE("{0}", event);
	}
};

class Sandbox : public Rambutan::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Rambutan::Application* Rambutan::CreateApplication()
{
	return new Sandbox();
}
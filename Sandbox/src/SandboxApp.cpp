#include <Minerva.h>

class ExampleLayer : public Minerva::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		MV_INFO("ExampleLayer::Update");
	}

	void OnEvent(Minerva::Event& event) override
	{
		MV_INFO("{0}", event);
	}
};

class Sandbox : public Minerva::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Minerva::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Minerva::Application* Minerva::CreateApplication()
{
	return new Sandbox();
}
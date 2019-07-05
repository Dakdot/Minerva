#include <Minerva.h>

#include "imgui/imgui.h"

class ExampleLayer : public Minerva::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		if (Minerva::Input::IsKeyPressed(MV_KEY_LEFT_SHIFT))
			MV_TRACE("Shift is being held");
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world!");
		ImGui::End();
	}

	void OnEvent(Minerva::Event& event) override
	{
		//MV_INFO("{0}", event);
	}
};

class Sandbox : public Minerva::Application
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

Minerva::Application* Minerva::CreateApplication()
{
	return new Sandbox();
}
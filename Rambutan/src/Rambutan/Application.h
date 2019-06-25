#pragma once

#include "Events/ApplicationEvent.h"

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Rambutan {

	class RAMBUTAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in the client
	Application* CreateApplication();

}

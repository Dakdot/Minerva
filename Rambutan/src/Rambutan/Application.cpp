#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Rambutan {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RB_TRACE(e);

		while (true);
	}

}
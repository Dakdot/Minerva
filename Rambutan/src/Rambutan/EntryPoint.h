#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Rambutan::Application* Rambutan::CreateApplication();

int main(int argc, char** argv)
{
	Rambutan::Log::Init();
	RB_CORE_WARN("Hey bitch!");
	int a = 5;
	RB_INFO("Hello! Var={0}", a);

	auto app = Rambutan::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Rambutan only supports Windows for the time being!
#endif
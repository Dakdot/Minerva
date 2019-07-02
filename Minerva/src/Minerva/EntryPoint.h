#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Minerva::Application* Minerva::CreateApplication();

int main(int argc, char** argv)
{
	Minerva::Log::Init();
	MV_CORE_WARN("Hey bitch!");
	int a = 5;
	MV_INFO("Hello! Var={0}", a);

	auto app = Minerva::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Minerva only supports Windows for the time being!
#endif
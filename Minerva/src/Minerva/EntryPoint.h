#pragma once

#ifdef MV_PLATFORM_WINDOWS

extern Minerva::Application* Minerva::CreateApplication();

int main(int argc, char** argv)
{
	Minerva::Log::Init();

	auto app = Minerva::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Minerva only supports Windows for the time being!
#endif
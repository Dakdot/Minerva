#pragma once

#ifdef RB_PLATFORM_WINDOWS
	#ifdef RB_BUILD_DLL
		#define RAMBUTAN_API __declspec(dllexport)
	#else
		#define RAMBUTAN_API __declspec(dllimport)
	#endif
#else
	#error Rambutan only supports Windows for the time being!
#endif
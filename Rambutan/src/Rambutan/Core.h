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

#ifdef RB_ENABLE_ASSERTS
	#define RB_ASSERT(x, ...) { if (!(x)) { RB_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RB_CORE_ASSERT(x, ...) { if (!(x)) { RB_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RB_ASSERT(x, ...)
	#define RB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#pragma once

#ifdef MV_PLATFORM_WINDOWS
	#ifdef MV_BUILD_DLL
		#define MINERVA_API __declspec(dllexport)
	#else
		#define MINERVA_API __declspec(dllimport)
	#endif
#else
	#error Minerva only supports Windows for the time being!
#endif

#ifdef MV_DEBUG
	#define MV_ENABLE_ASSERTS
#endif

#ifdef MV_ENABLE_ASSERTS
	#define MV_ASSERT(x, ...) { if (!(x)) { MV_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MV_CORE_ASSERT(x, ...) { if (!(x)) { MV_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MV_ASSERT(x, ...)
	#define MV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MV_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
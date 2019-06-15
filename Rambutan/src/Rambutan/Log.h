#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rambutan {

	class RAMBUTAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log Macros

#define RB_CORE_TRACE(...)      ::Rambutan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RB_CORE_INFO(...)       ::Rambutan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RB_CORE_WARN(...)       ::Rambutan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RB_CORE_ERROR(...)      ::Rambutan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RB_CORE_FATAL(...)      ::Rambutan::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros

#define RB_TRACE(...)           ::Rambutan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RB_INFO(...)            ::Rambutan::Log::GetClientLogger()->info(__VA_ARGS__)
#define RB_WARN(...)            ::Rambutan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RB_ERROR(...)           ::Rambutan::Log::GetClientLogger()->error(__VA_ARGS__)
#define RB_FATAL(...)           ::Rambutan::Log::GetClientLogger()->fatal(__VA_ARGS__)
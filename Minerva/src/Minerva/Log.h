#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Minerva {

	class Minerva_API Log
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

#define MV_CORE_TRACE(...)      ::Minerva::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MV_CORE_INFO(...)       ::Minerva::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MV_CORE_WARN(...)       ::Minerva::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MV_CORE_ERROR(...)      ::Minerva::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MV_CORE_FATAL(...)      ::Minerva::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros

#define MV_TRACE(...)           ::Minerva::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MV_INFO(...)            ::Minerva::Log::GetClientLogger()->info(__VA_ARGS__)
#define MV_WARN(...)            ::Minerva::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MV_ERROR(...)           ::Minerva::Log::GetClientLogger()->error(__VA_ARGS__)
#define MV_FATAL(...)           ::Minerva::Log::GetClientLogger()->fatal(__VA_ARGS__)
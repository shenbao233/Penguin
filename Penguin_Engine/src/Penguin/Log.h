#pragma once

#include "core.h"
#include "spdlog/spdlog.h"

namespace Penguin {

	class PENGUIN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;



		Log();
		~Log(); 
	};
}

// Core Log macros
#define PG_CORE_FATAL(...) ::Penguin::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define PG_CORE_ERROR(...) ::Penguin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PG_CORE_WARN(...) ::Penguin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PG_CORE_INFO(...) ::Penguin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PG_CORE_TRACE(...) ::Penguin::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Clent Log macros
#define PG_CLIENT_FATAL(...) ::Penguin::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define PG_CLIENT_ERROR(...) ::Penguin::Log::GetClientLogger()->error(__VA_ARGS__)
#define PG_CLIENT_WARN(...) ::Penguin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PG_CLIENT_INFO(...) ::Penguin::Log::GetClientLogger()->info(__VA_ARGS__)
#define PG_CLIENT_TRACE(...) ::Penguin::Log::GetClientLogger()->trace(__VA_ARGS__)

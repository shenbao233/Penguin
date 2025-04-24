#pragma once

#ifdef  PG_PLATFORM_WINDOWS
	#ifdef PG_BUILD_DLL
		#define PENGUIN_API __declspec(dllexport)
	#else
		#define PENGUIN_API __declspec(dllimport)
	#endif
#else
	#error Penguin only support Windows!
#endif //  PG_PLATFORM_WINDOWS

#ifdef PG_ENABLE_ASSERTS
	#define PG_CLIENT_ASSERT(x, ...) {if(!(x)) {PG_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define PG_CORE_ASSERT(x, ...) {if (!(x)) {PG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define PG_CLIENT_ASSERT(x, ...)
	#define PG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

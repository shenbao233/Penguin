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

#pragma once 

#include "core.h"

namespace Penguin {

	class PENGUIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in the client.
	Application* CreateApplication();

}



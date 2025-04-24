#pragma once 

#include "core.h"
#include "Events/Event.h"
#include "Penguin/Events/ApplicationEvent.h"

#include "Window.h"

namespace Penguin {

	class PENGUIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	// To be defined in the client.
	Application* CreateApplication();

}



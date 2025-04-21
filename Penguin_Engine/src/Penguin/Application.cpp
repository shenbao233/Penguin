#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"

namespace Penguin {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PG_CLIENT_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
		{
			PG_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryApplication))
		{
			PG_CLIENT_TRACE(e);
		}
		while (1);
	}
}

#include "nvpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Nova/Log.h"

namespace Nova
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		NOVA_TRACE(e);

		while (true);
	}
}
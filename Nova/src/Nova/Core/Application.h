#pragma once

#include "Nova/Core/Core.h"
#include "Nova/Events/Event.h"

namespace Nova
{
	class NOVA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();
}
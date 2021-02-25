#pragma once

#include "Nova/Core/Core.h"
#include "Nova/Core/Window.h"
#include "Nova/Core/LayerStack.h"

#include "Nova/Events/Event.h"
#include "Nova/Events/ApplicationEvent.h"

namespace Nova
{

	class NOVA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	Application* CreateApplication();

}
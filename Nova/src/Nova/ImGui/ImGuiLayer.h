#pragma once

#include "Nova/Core/Layer.h"

namespace Nova
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
	};
}
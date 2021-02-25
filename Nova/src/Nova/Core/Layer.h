#pragma once

#include "Nova/Core/Core.h"
#include "Nova/Events/Event.h"

namespace Nova
{ 
	
	class NOVA_API Layer
	{
	public:
		Layer(const std::string & = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
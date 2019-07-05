#pragma once

#include "Minerva/Layer.h"

#include "Minerva/Events/KeyEvent.h"
#include "Minerva/Events/MouseEvent.h"
#include "Minerva/Events/ApplicationEvent.h"

namespace Minerva {

	class MINERVA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;

	};

}
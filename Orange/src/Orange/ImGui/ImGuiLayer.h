#pragma once

#include "Orange/Core/Layer.h"

#include "Orange/Events/ApplicationEvent.h"
#include "Orange/Events/KeyEvent.h"
#include "Orange/Events/MouseEvent.h"


namespace Orange {

	class ORANGE_API ImGuiLayer : public Layer {

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}

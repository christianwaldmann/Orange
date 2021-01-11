#pragma once

#include "Orange.h"


namespace Orange {
	class EditorLayer : public Layer {

	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Event& event) override;

	private:
		OrthographicCameraController m_CameraController;

		// TEMP
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<Framebuffer> m_Framebuffer;

		Ref<Texture2D> m_CheckerboardTexture;

		glm::vec2 m_ViewportSize = { 0, 0 };

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	};
}

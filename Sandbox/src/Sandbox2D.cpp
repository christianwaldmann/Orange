#include "Sandbox2D.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>


Sandbox2D::Sandbox2D() : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {}


void Sandbox2D::OnAttach() {
	OG_PROFILE_FUNCTION();

	m_CheckerboardTexture = Orange::Texture2D::Create("assets/textures/Checkerboard.png");
}


void Sandbox2D::OnDetach() {
	OG_PROFILE_FUNCTION();

}


void Sandbox2D::OnUpdate(Orange::Timestep ts) {
	OG_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		OG_PROFILE_SCOPE("Renderer Prep");
		Orange::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Orange::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		OG_PROFILE_SCOPE("Renderer Draw");
		Orange::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Orange::Renderer2D::DrawQuadRotated({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Orange::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Orange::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Orange::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));
		Orange::Renderer2D::DrawQuadRotated({ -2.0f, 0.0f, 0.0f }, { 2.0f, 2.0f }, rotation, m_CheckerboardTexture, 20.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));

		Orange::Renderer2D::EndScene();
	}
}


void Sandbox2D::OnImGuiRender() {
	OG_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}


void Sandbox2D::OnEvent(Orange::Event& event) {
	m_CameraController.OnEvent(event);
}


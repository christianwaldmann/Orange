#include "ogpch.h"
#include "OrthographicCameraController.h"

#include "Orange/Core/Input.h"
#include "Orange/Core/KeyCodes.h"


namespace Orange {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool enableRotation) : m_AspectRatio(aspectRatio), m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top), m_EnableRotation(enableRotation) {

	}


	void OrthographicCameraController::OnUpdate(Timestep ts) {
		OG_PROFILE_FUNCTION();

		if (Input::IsKeyPressed(OG_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(OG_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;

		if (Input::IsKeyPressed(OG_KEY_W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		if (Input::IsKeyPressed(OG_KEY_S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

		if (m_EnableRotation) {
			if (Input::IsKeyPressed(OG_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(OG_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel;
	}


	void OrthographicCameraController::OnEvent(Event& e) {
		OG_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(OG_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(OG_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}


	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e) {
		OG_PROFILE_FUNCTION();

		m_ZoomLevel -= 0.25f * e.GetYOffset();
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
		return false;
	}


	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e) {
		OG_PROFILE_FUNCTION();

		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
		return false;
	}

}

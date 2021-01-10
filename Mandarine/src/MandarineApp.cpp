#include <Orange.h>
#include <Orange/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "EditorLayer.h"


namespace Orange {

	class Mandarine : public Orange::Application {

	public:
		Mandarine() : Application("Mandarine") {
			PushLayer(new EditorLayer());
		}


		~Mandarine() {

		}
	};


	Orange::Application* Orange::CreateApplication() {
		return new Mandarine();
	}

}

#include "ogpch.h"
#include "Renderer.h"


namespace Orange {

	void Renderer::BeginScene() {}


	void Renderer::EndScene() {}


	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}

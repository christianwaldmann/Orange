#include "ogpch.h"
#include "Framebuffer.h"

#include "Orange/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"


namespace Orange {



	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None:
			OG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLFramebuffer>(spec);
		}

		OG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

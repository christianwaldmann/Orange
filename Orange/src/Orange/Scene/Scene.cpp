#include "ogpch.h"
#include "Scene.h"

#include "Components.h"
#include "Orange/Renderer/Renderer2D.h"

#include <glm/glm.hpp>


namespace Orange {

	Scene::Scene() {

		struct TransformComponent {
			glm::mat4 Transform;

			TransformComponent() = default;
			TransformComponent(const TransformComponent&) = default;
			TransformComponent(const glm::mat4& transform) : Transform(transform) {}
		};

		entt::entity entity = m_Registry.create();
	}


	Scene::~Scene() {

	}

	entt::entity Scene::CreateEntity() {
		return m_Registry.create();
	}


	void Scene::OnUpdate(Timestep ts) {
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group) {
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}

}

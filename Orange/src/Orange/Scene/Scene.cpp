#include "ogpch.h"
#include "Scene.h"

#include "Components.h"
#include "Orange/Renderer/Renderer2D.h"

#include "Entity.h"

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


	Entity Scene::CreateEntity(const std::string& name) {
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}


	void Scene::OnUpdate(Timestep ts) {
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group) {
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}

}

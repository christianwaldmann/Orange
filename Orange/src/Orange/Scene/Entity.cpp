#include "ogpch.h"
#include "Entity.h"


namespace Orange {

	Entity::Entity(entt::entity handle, Scene* scene) : m_EntityHandle(handle), m_Scene(scene) {}

}

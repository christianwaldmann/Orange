#pragma once

#include "Orange/Core/Core.h"
#include "Orange/Core/Log.h"
#include "Orange/Scene/Scene.h"
#include "Orange/Scene/Entity.h"


namespace Orange {

	class SceneHierarchyPanel {

	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

		Entity GetSelectedEntity() const { return m_SelectionContext; }

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}

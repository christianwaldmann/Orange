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

	private:
		void DrawEntityNode(Entity entity);

	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}

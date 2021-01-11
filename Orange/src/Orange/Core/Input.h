#pragma once

#include "Orange/Core/Core.h"


namespace Orange {

	class ORANGE_API Input {

	public:
		static bool IsKeyPressed(int keycode);
		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}

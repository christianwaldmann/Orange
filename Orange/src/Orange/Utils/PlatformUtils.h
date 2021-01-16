#pragma once

#include <string>


namespace Orange {

	class FileDialogs {

	public:
		// These eturn empty strings if cancelled
		static std::string OpenFile(const char* filter);
		static std::string SaveFile(const char* filter);
	};

}

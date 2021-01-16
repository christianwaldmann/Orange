workspace "Orange"
	architecture "x64"
	startproject "Mandarine"
	require "codeblocks"

	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Orange/vendor/GLFW/include"
IncludeDir["Glad"] = "Orange/vendor/Glad/include"
IncludeDir["ImGui"] = "Orange/vendor/imgui"
IncludeDir["glm"] = "Orange/vendor/glm"
IncludeDir["stb_image"] = "Orange/vendor/stb_image"
IncludeDir["entt"] = "Orange/vendor/entt/include"
IncludeDir["yaml_cpp"] = "Orange/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "Orange/vendor/imguizmo"


group "Dependencies"
	include "Orange/vendor/GLFW"
	include "Orange/vendor/Glad"
	include "Orange/vendor/imgui"
	include "Orange/vendor/yaml-cpp"


group ""


project "Orange"
	location "Orange"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	pchheader "ogpch.h"
	pchsource "Orange/src/ogpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/imguizmo/ImGuizmo.h",
		"%{prj.name}/vendor/imguizmo/ImGuizmo.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"IMGUI_IMPL_OPENGL_LOADER_GLAD",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
	}

	filter "files:Orange/vendor/imguizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"OG_PLATFORM_WINDOWS",
			"OG_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
		}

	filter "configurations:Debug"
		defines "OG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OG_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Orange/vendor/spdlog/include",
		"Orange/vendor",
		"Orange/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
	}

	links
	{
		"Orange"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"OG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "OG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OG_DIST"
		runtime "Release"
		optimize "on"
		


project "Mandarine"
	location "Mandarine"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Orange/vendor/spdlog/include",
		"Orange/vendor",
		"Orange/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}",
	}

	links
	{
		"Orange"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"OG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "OG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OG_DIST"
		runtime "Release"
		optimize "on"

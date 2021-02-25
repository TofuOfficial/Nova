workspace "Nova"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Nova/vendor/GLFW/include"

include "Nova/vendor/GLFW"

project "Nova"
	location "Nova"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nvpch.h"
	pchsource "Nova/src/nvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NOVA_PLATFORM_WINDOWS",
			"NOVA_BUILD_DLL",
			"NOVA_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NOVA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NOVA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NOVA_DIST"
		optimize "On"

project "Sandbox"
	location "Nova"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nova/vendor/spdlog/include",
		"Nova/src"
	}

	links
	{
		"Nova"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NOVA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NOVA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NOVA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "NOVA_DIST"
		optimize "On"
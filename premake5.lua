workspace "Minerva"
architecture "x64"
startproject "Sandbox"

configurations {
    "Debug",
    "Release",
    "Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Minerva/vendor/GLFW/include"
IncludeDir["Glad"] = "Minerva/vendor/Glad/include"
IncludeDir["ImGui"] = "Minerva/vendor/imgui"
IncludeDir["glm"] = "Minerva/vendor/glm"

group "Dependencies"
    include "Minerva/vendor/GLFW"
    include "Minerva/vendor/Glad"
    include "Minerva/vendor/ImGui"

group ""

project "Minerva"
    location "Minerva"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mvpch.h"
    pchsource "Minerva/src/mvpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "MV_PLATFORM_WINDOWS",
            "MV_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "MV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MV_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MV_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "Minerva/vendor/spdlog/include",
        "Minerva/src",
        "%{IncludeDir.glm}"
    }

    links {
        "Minerva"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines {
            "MV_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "MV_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "MV_DIST"
        runtime "Release"
        optimize "On"
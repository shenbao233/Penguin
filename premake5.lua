workspace "Penguin"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    buildoptions {"/utf-8"}

outputdir = "%{cfg.buildcfg}_%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Penguin_Engine/Vendor/GLFW/include"

include "Penguin_Engine/Vendor/GLFW"

project "Penguin_Engine"
    location "Penguin_Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pgpch.h"
    pchsource "Penguin_Engine/src/pgpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Penguin_Engine/src",
        "Penguin_Engine/Vendor/spdlog/include",
        "Penguin_Engine/Events",
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
            "PG_PLATFORM_WINDOWS",
            "PG_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
        
    filter "configurations:Debug"
        defines "PG_DEBUG"
       symbols "On"

    filter "configurations:Release"
        defines "PG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PG_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
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
        "Penguin_Engine/Vendor/spdlog/include",
        "Penguin_Engine/src"
    }

    links
    {
        "Penguin_Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PG_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PG_DIST"
        optimize "On"
    

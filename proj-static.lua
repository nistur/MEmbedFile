project "MEmbedFileStatic"
    kind "StaticLib"
    language "C++"

    -- include all the files, including Maratis SDK ones
    files {
        "src/**.cpp",
        "include/**.h",
        "**.md",
        os.getenv("MSDKDIR") .. "SDK/**.h"
    }
    includedirs { "include" }
    targetdir "bin"
    targetname "MEmbedFile"

    -- split the files up a bit nicer inside Visual Studio
    vpaths { 
        ["MCore/*"] = os.getenv("MSDKDIR") .. "/SDK/MCore/Includes/**.h",
        ["MEngine/*"] = os.getenv("MSDKDIR") .. "/SDK/MEngine/Includes/**.h",
        ["Plugin/*"] = { "**.h", "**.cpp" },
        ["Doc/*"] = { "**.md" }
    }
    defines { "M_EMBED_FILE_STATIC" }
    -- link to Maratis
    links { "MCore", "MEngine" }
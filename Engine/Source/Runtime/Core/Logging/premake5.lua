function includeLogging()
    files {
        PhanesRuntime .. "/Core/Logging/**.h",
        PhanesRuntime .. "/Core/Logging/**.cpp",
    } 

    -- includedirs { PhanesThirdParty .. "/spdlog/include" }

    pchheader (PhanesRuntime .. "/Core/Logging/LoggingPCH.h")
    pchsource (PhanesRuntime .. "/Core/Logging/private/LoggingPCH.cpp")
end
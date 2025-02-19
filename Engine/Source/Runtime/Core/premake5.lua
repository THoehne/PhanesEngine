include (PhanesRuntime .. "/Core/StartingPoint/premake5.lua")
include (PhanesRuntime .. "/Core/Logging/premake5.lua")


project "PhanesCore"
    kind "StaticLib"

    boilerplate()

    files {
        PhanesRuntime .. "/Core/Core.h"
    }

    includedirs { PhanesRuntime }

    includeStartingPoint()
    includeLogging()
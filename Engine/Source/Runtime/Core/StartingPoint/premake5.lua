function includeStartingPoint()
    files {
        PhanesRuntime .. "/Core/StartingPoint/**.h",
        PhanesRuntime .. "/Core/StartingPoint/**.cpp",
    }

    pchheader (PhanesRuntime .. "/Core/StartingPoint/StartingPointPCH.h")
    pchsource (PhanesRuntime .. "/Core/StartingPoint/private/StartingPointPCH.cpp")
end
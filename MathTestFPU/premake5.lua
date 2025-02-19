project "MathTestFPU"
    kind "ConsoleApp"
    boilerplate()

    files {
        phanesRoot .. "/MathTestFPU/test.cpp"
    }

    buildoptions {"-Wno-unused-variable", "-w", "-fpermissive"}

    pchheader "pch.h"
    pchsource "pch.cpp"

    includedirs {
        phanesRoot .. "/MathTestFPU",
        PhanesRuntime
    }

project "Test"
    kind "ConsoleApp"
    boilerplate()

    files {
        phanesRoot .. "/MathTestFPU/main.cpp"
    }

    includedirs {
        PhanesRuntime
    }
project "gtest"
    language "C++"
    kind "StaticLib"
    third_party_boilerplate()

    includedirs { 
    
        PhanesThirdParty .. "/googletest/googletest/include", 
        PhanesThirdParty .. "/googletest/googletest/include/gtest",
        PhanesThirdParty .. "/googletest/googletest" 
    
    }
    files { 
        PhanesThirdParty .. "/googletest/googletest/src/**.cc", 
        PhanesThirdParty .. "/googletest/googletest/include/gtest/**.h" 
    }

project "MathTestFPU"
    kind "ConsoleApp"
    boilerplate()

    files {
        PhanesRuntime .. "/Core/Tests/Math/MathTestFPU/test.cpp"
    }

    buildoptions {"-Wno-unused-variable", "-w", "-fpermissive"}

    pchheader (PhanesRuntime .. "/Core/Tests/Math/MathTestFPU/pch.h")
    pchsource (PhanesRuntime .. "/Core/Tests/Math/MathTestFPU/pch.cpp")

    links { "gtest" }
    dependson { "gtest" }

    includedirs {
        PhanesRuntime .. "/Core/Tests/Math/MathTestFPU",
        PhanesThirdParty .. "/googletest/googletest/include",
        PhanesThirdParty,
        PhanesRuntime
    }
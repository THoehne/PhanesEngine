project "DevPlayground"
    kind "ConsoleApp"

    boilerplate()

    files {
        phanesRoot .. "/DevPlayground/**.h",
        phanesRoot .. "/DevPlayground/**.cpp",
    }

    -- Linking PhanesCore
    links { "PhanesCore" }
    dependson { "PhanesCore" }

    links{"fmt"}
    dependson {"fmt"}

    includedirs { PhanesRuntime }
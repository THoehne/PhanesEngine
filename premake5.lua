-- Phanes build configuration
VERSION = "1.0.0"

-- Override with specific platform if necessary
PLATFORM = os.target() 

-- architecture. 
ARCH = "x86_64"

-- SSE options:
-- SSE4: SSE
-- AVX: AVX
-- AVX2: AVX2
-- No SSE: FPU
-- None: Automatically detect SSE during build
SSE = "None"


phanesRoot = path.getabsolute(".") 
phanesBin = path.join(phanesRoot, "bin")
phanesInt = path.join(phanesRoot, ".int")
phanesBuildFiles = path.join(phanesRoot, "build")

PhanesEngine = path.join(phanesRoot, "Engine")
PhanesRuntime = path.join(PhanesEngine, "Source/Runtime")
PhanesThirdParty = path.join(PhanesEngine, "Source/ThirdParty")



workspace "PhanesEngine"
   cppdialect "C++20"
   architecture (ARCH)
   toolset "gcc"
   flags { "MultiProcessorCompile" }
   clangtidy "On"
   debugger "gdb"
   startproject "MathTestFPU"
   configurations { "Debug", "Release" }


function linux_sse() 
   if SSE == "SSE" then
      defines {"P_SSE__"}
      buildoptions {"-msse4", "-msse2", "-msse3"}
   elseif SSE == "AVX" then
      defines { "P_AVX__" }
      buildoptions {"-mavx", "-msse4", "-msse2", "-msse3"}
   elseif SSE == "AVX2" then
      defines { "P_AVX2__" }
      buildoptions {"-mavx2", "-mavx", "-msse4", "-msse2", "-msse3"}
   elseif SSE == "FPU" then
      defines { "P_FORCE_FPU" }
   end

end

function boilerplate()
   language "C++"

   location (phanesBuildFiles .. "/%{prj.name}")
   targetdir (phanesBin .. "/" .. VERSION .. "/%{cfg.buildcfg}/%{prj.name}")
   objdir (phanesInt .. "/" .. VERSION .. "/%{cfg.buildcfg}/%{prj.name}")

   if PLATFORM == "linux" then
      defines { "P_LINUX_BUILD" }
      buildoptions {"-Wall", "-Wextra", "-Werror"}
      linux_sse()
      buildoptions { "-Wno-unused-parameter" , "-fms-extensions" }
   end

   filter "configurations:Debug"
      defines { "DEBUG", "TRACE", "P_DEBUG"}
      symbols "On"
      buildmessage("Building %{prj.name} in debug mode")

   filter "configurations:Release"
      defines { "NDEBUG", "P_RELEASE" }
      linktimeoptimization "On"
      optimize "On"
      intrinsics "On"
      buildmessage("Building %{prj.name} in release mode")

   filter{}
end

function third_party_boilerplate()
   language "C++"

   location (phanesBuildFiles .. "/%{prj.name}")
   targetdir (phanesBin .. "/" .. VERSION .. "/%{cfg.buildcfg}/%{prj.name}")
   objdir (phanesInt .. "/" .. VERSION .. "/%{cfg.buildcfg}/%{prj.name}")

   if PLATFORM == "linux" then
      buildoptions {"-Wall", "-Wextra", "-Werror"}
      linux_sse()
   end

   filter "configurations:Debug"
      defines { "DEBUG", "TRACE", "P_DEBUG"}
      symbols "On"
      buildmessage("Building %{prj.name} in debug mode")

   filter "configurations:Release"
      defines { "NDEBUG", "P_RELEASE" }
      linktimeoptimization "On"
      optimize "On"
      intrinsics "On"
      buildmessage("Building %{prj.name} in release mode")

   filter{}
end

-- actions

function action_clean()
   os.rmdir(phanesBin)
   os.rmdir(phanesInt)
   os.rmdir(phanesBuildFiles)
   os.remove(phanesRoot .. "/Makefile")
end

newaction {
   trigger = "clean",
   description = "Clean the build",
   execute = action_clean,
}

-- includeProjects here
include (phanesRoot .. "/Engine/Source/Runtime/Core/premake5.lua")
include (phanesRoot .. "/DevPlayground/premake5.lua")
include (PhanesRuntime .. "/Core/Tests/Math/MathTestFPU/premake5.lua")
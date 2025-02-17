cmake_minimum_required(VERSION 3.15...3.30)

project(PhanesCore)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(Logging/CMakeLists.txt)
include(StartingPoint/CMakeLists.txt)

add_library(PhanesCore STATIC 
Core.h 
${Logging}
${StartingPoint}
)

target_precompile_headers(PhanesCore PUBLIC 
${LoggingPCH}
${StartingPointPCH}
)

add_compile_definitions(P_LINUX_BUILD)
add_compile_definitions(P_DEBUG)


target_include_directories(PhanesCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../)
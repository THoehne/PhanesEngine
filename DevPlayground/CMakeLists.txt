cmake_minimum_required(VERSION 3.15...3.30)

project(DevPlayground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")  

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../Engine/Source/Runtime ${CMAKE_BINARY_DIR}/Engine)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}../Engine/Source/Runtime)

add_executable(DevPlayground 
    DevPlayground.cpp
)


add_compile_definitions(P_LINUX_BUILD)
add_compile_definitions(P_DEBUG)

target_link_libraries(DevPlayground PRIVATE PhanesCore)
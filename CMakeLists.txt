cmake_minimum_required(VERSION 2.8)
project(demo-scene)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# CMAKE extensions
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Required packages
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Freetype REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c++11")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# include locations
include_directories(${SDL2_INCLUDE_DIR})
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories(${FREETYPE_INCLUDE_DIRS})

set(SOURCES
        src/main.cpp
        src/application/Application.cpp
        src/utils/BaseLog.cpp
        src/utils/COutLog.cpp
        src/application/Shader.cpp
        src/application/Object.cpp
        src/application/Character.cpp)

add_executable(demo ${SOURCES})

target_link_libraries(demo
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
        GLEW
        freetype
)

cmake_minimum_required(VERSION 3.5)
project(Engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES src/main.cpp src/graphics/window.cpp src/graphics/window.h)

add_executable(Engine ${SOURCE_FILES})

# Find and link GLEW
set(GLEW_LINK ${PROJECT_SOURCE_DIR}/deps/lib/libGLEW.a)
target_link_libraries(Engine ${GLEW_LINK})

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(Engine ${OPENGL_LIBRARIES})

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/deps/include)

# Set GLFW variables to not build anything but GLFW
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

# Setup GLFW
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/deps/GLFW)
add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

# Include anything we need
include_directories(${INCLUDE_DIR})

target_link_libraries(Engine ${GLEW_LINK} glfw ${GLFW_LBRARIES})
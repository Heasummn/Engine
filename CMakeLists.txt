cmake_minimum_required(VERSION 3.5)
project(Engine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
set(LINK_FILE ${PROJECT_SOURCE_DIR}/deps/lib/libGLEW.so)
set(INCLUDE_DIR deps/include)
set(LIB_DIR deps/lib)

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

# Link anything we need
link_directories(${LIB_DIR})

add_executable(Engine ${SOURCE_FILES})
target_link_libraries(Engine ${LINK_FILE} glfw ${GLFW_LBRARIES})
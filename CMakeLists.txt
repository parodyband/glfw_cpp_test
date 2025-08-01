cmake_minimum_required(VERSION 3.15)
project(my_project CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
  message(STATUS "No build type specified, defaulting to ${CMAKE_BUILD_TYPE}")
endif()

# Set build-type-specific flags.
# -g: include debug information
# -O3: optimization level
# -DNDEBUG: disable asserts
# -Wall: enable all warnings
# -Werror: treat warnings as errors
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -Wall -Werror)
else() # Release or other types
    add_compile_options(-O3 -DNDEBUG -Wall)
endif()

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.cpp")
add_executable(my_project ${SOURCES})

target_link_libraries(my_project PRIVATE glfw OpenGL::GL)

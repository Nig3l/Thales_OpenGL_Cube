cmake_minimum_required(VERSION 3.15)
project(OpenGL_Thales_Cube)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes/glm)
include_directories(includes/glfw)
include_directories(includes/cwalk)
include_directories(includes/glad/include)

add_executable(OpenGL_Thales_Cube src/Thales_Cube.cpp includes/cwalk/cwalk.c includes/glad/glad.c src/shader/ShaderProgram.cpp src/shader/ShaderProgram.h src/shader/ShaderBuilder.cpp src/shader/ShaderBuilder.h src/shader/Shader.cpp src/shader/Shader.h src/shader/ShaderProgramBuilder.cpp src/shader/ShaderProgramBuilder.h src/texture/Texture.cpp src/texture/Texture.h src/shape/Cube.cpp src/shape/Cube.h src/tools/TranslationTool.cpp src/tools/TranslationTool.h src/shape/Pyramid.cpp src/shape/Pyramid.h src/shape/Shape.cpp src/shape/Shape.h src/texture/TextureFactory.cpp src/texture/TextureFactory.h src/shape/ShapeFactory.cpp src/shape/ShapeFactory.h)
if (UNIX)
    MESSAGE("-- Linux Compilation")
    target_link_libraries(OpenGL_Thales_Cube GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor)
endif(UNIX)

if (WIN32)
    MESSAGE("-- Windows Compilation")
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(lib/glfw-3.3.1)
    target_link_libraries(OpenGL_Thales_Cube glfw)
endif(WIN32)
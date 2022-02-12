cmake_minimum_required(VERSION 3.0.0)
project(opengl-experimenting VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(./libs/glfw)

include_directories(./includes)

add_executable(${PROJECT_NAME}
	./src/Application.cpp 
	./includes/glad.c
	./src/Renderer.cpp
	./src/IndexBuffer.cpp
	./src/VertexBuffer.cpp
	./src/VertexArray.cpp
	./src/Shader.cpp
	./src/Texture.cpp
)

target_link_libraries(${PROJECT_NAME} glfw)

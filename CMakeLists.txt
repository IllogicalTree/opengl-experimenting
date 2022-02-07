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
add_subdirectory(./libs/glfw-3.3.6)

include_directories(./includes)

add_executable(${PROJECT_NAME}
	./src/main.cpp 
	./includes/glad.c
)

target_link_libraries(${PROJECT_NAME} glfw)

#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(call) while (glGetError() != GL_NO_ERROR);    \
	call;                                                    \
	ASSERT(GlLogCall(#call, __FILE__, __LINE__));

bool GlLogCall(const char* function, const char* file, int line);
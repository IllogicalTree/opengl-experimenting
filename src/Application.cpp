#include "Renderer.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Debug.h"

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}
 
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		 glfwSetWindowShouldClose(window, GLFW_TRUE);
	}  
}
 
int main(void) {
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);
 
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
	}
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
 
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glfwSwapInterval(1);
 
	float positions[] = {
	   	-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f, 0.5f,
		-0.5f,  0.5f,
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb(positions, 4 * 2 * sizeof(float));
	IndexBuffer ib(indicies, 6);

	VertexBufferLayout layout;
	layout.AddFloat(2);
	va.AddBuffer(vb, layout);

	Shader shader("./res/shaders/basic.glsl");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);

	va.Unbind();
    vb.Unbind();
	ib.Unbind();
	shader.Unbind();

	Renderer renderer;

	float r = 0.0f;
	float increment = 0.05f;
    while (!glfwWindowShouldClose(window)) {

		renderer.Clear();
		
		shader.Bind();
		shader.SetUniform4f("u_Color", r, 0.0f, 1.0f, 1.0f);
		
		renderer.Draw(va, ib, shader);

		if (r > 1.0f) {
			increment = -0.05f;
		} else if (r < 0.0f) {
			increment = 0.05f;
		}
		r += increment;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
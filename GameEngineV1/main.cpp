#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Model.h"

GLfloat triangleVerts[] = {
	-0.5f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f
};

int main(int argc, char** argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(1024, 768, "Hello GL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	Shader simplerShader("D:\\Code\\cpp\\Shaders\\Simple.vs", "D:\\Code\\cpp\\Shaders\\Simple.frag");

	Model triangle(triangleVerts, sizeof(triangleVerts));
	triangle.Setup();

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		triangle.Draw(&simplerShader);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}

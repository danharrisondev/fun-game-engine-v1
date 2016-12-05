#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"

Vertex triangleVerts[3] = {
	Vertex(0.0f, 0.5f, 0.0f),
	Vertex(0.5f, -0.5f, 0.0f),
	Vertex(-0.5f, -0.5f, 0.0f)
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

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, 1024, 768);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	Mesh triangleMesh(triangleVerts, sizeof(triangleVerts));
	Shader simplerShader("Shaders\\simple-movable.vs", "Shaders\\simple-movable.frag");

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		triangleMesh.Draw(simplerShader);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}
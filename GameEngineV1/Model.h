#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

class Model
{
public:
	Model(GLfloat* vertices, GLsizei size);
	~Model();
	void Setup();
	void Draw(Shader* shader);
	glm::vec3 Position;
private:
	GLuint mVertexArray;
	GLfloat* mVertices;
	GLuint mVertexCount;
	GLsizei mSize;
};


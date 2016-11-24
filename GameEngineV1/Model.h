#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "Vertex.h"

class Model
{
public:
	Model(Vertex* vertices, GLsizei size);
	~Model();
	void Setup();
	void Draw(Shader& shader);
	glm::vec3 Position;
private:
	GLuint mVertexArray;
	Vertex* mVertices;
	GLuint mVertexCount;
	GLsizei mSize;
};


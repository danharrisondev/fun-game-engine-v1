#pragma once
#include <GL/glew.h>
#include "Shader.h"

class Model
{
public:
	Model(GLfloat* vertices, GLsizei size);
	~Model();
	void Setup();
	void Draw(Shader* shader);
private:
	GLuint mVertexArray;
	GLfloat* mVertices;
	GLuint mVertexCount;
	GLsizei mSize;
};


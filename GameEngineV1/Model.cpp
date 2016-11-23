#include "Model.h"
#include "Shader.h"


Model::Model(GLfloat* vertices, GLsizei size)
{
	mVertices = vertices;
	mSize = size;
}

Model::~Model()
{
}

void Model::Setup()
{
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);
	
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, mSize, mVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Model::Draw(Shader* shader)
{
	shader->Use();
	glBindVertexArray(mVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

#include "Model.h"
#include "Shader.h"
#include "Vertex.h"


Model::Model(Vertex* vertices, GLsizei size)
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

void Model::Draw(Shader& shader)
{
	glm::mat4 model;
	model = glm::translate(model, Position);

	glm::mat4 view;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	glm::mat4 projection;
	projection = glm::perspective(45.0f, 1024.0f/768.0f, 0.1f, 100.0f);

	shader.Use();
	glUniformMatrix4fv(shader.GetUniformLocation("model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(shader.GetUniformLocation("view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(shader.GetUniformLocation("projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(mVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
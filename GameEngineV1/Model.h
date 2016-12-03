#pragma once
#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include "Mesh.h"

class Model
{
public:
	Model(Mesh& mesh);
	~Model();
	void Setup();
	void Draw(Shader& shader);
	glm::vec3 Position;
private:
	GLuint mVertexArray;
	Vertex* mVertices;
	GLuint mVertexCount;
	GLsizei mSize;
	Mesh& mMesh;
};


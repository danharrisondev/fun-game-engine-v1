#ifndef MESH_H
#define MESH_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vertex.h"
#include "Shader.h"

class Mesh
{
	GLuint mVertexArray;
public:
	Mesh(const Vertex* vertices, const GLsizei size);
	void Draw(Shader& shader);
	const Vertex* data;
	const GLsizei size;
};

#endif
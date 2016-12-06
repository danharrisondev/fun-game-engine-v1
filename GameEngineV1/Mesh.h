#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "Vertex.h"
#include "Shader.h"
#include <vector>

class Mesh
{
	GLuint mVertexArray;
	GLuint mVertexBuffer;
	GLuint mElementBuffer;
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
public:
	Mesh(std::string modelPath);
	void Draw(Shader& shader);
};

#endif

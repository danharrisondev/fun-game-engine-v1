#ifndef MESH_H
#define MESH_H
#include <GL/glew.h>
#include "Vertex.h"

class Mesh
{
public:
	Mesh(const Vertex* vertices, const GLsizei size);
	const Vertex* data;
	const GLsizei size;
};

#endif
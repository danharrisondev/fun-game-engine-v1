#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glew.h>

struct Vertex
{
	Vertex(GLfloat x, GLfloat y, GLfloat z) : X(x), Y(y), Z(z)
	{
	}

	GLfloat X, Y, Z;
};

#endif

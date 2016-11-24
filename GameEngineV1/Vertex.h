#pragma once
#include <GL/glew.h>

struct Vertex
{
public:
	Vertex(GLfloat x, GLfloat y, GLfloat z) : X(x), Y(y), Z(z) { }
	GLfloat X, Y, Z;
};

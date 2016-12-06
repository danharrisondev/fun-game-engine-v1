#ifndef MESH_H
#define MESH_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vertex.h"
#include "Shader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>
#include <GLFW\glfw3.h>

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
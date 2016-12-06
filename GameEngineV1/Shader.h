#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <GL/glew.h>

class Shader
{
public:
	Shader(std::string vertexFilePath, std::string fragmentFilePath);
	~Shader();
	void Use();
	GLuint GetUniformLocation(const GLchar* name);
private:
	GLuint mProgramId;
};

#endif

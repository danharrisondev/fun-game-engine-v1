#include "Shader.h"
#include <GL/glew.h>


Shader::Shader(std::string vertexFilePath, std::string fragmentFilePath)
{
	std::ifstream vertexShaderFile(vertexFilePath);
	std::ifstream fragmentShaderFile(fragmentFilePath);
	std::stringstream vertexShaderBuffer;
	std::stringstream fragmentShaderBuffer;
	vertexShaderBuffer << vertexShaderFile.rdbuf();
	fragmentShaderBuffer << fragmentShaderFile.rdbuf();
	std::string vertexShaderString = vertexShaderBuffer.str();
	std::string fragmentShaderString = fragmentShaderBuffer.str();
	const char* vertexShaderCString = vertexShaderString.c_str();
	const char* fragmentShaderCString = fragmentShaderString.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderCString, nullptr);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderCString, nullptr);
	glCompileShader(fragmentShader);
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	this->mProgramId = program;
}

Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::Use()
{
	glUseProgram(this->mProgramId);
}

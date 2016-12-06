#version 330 core

in vec3 colorOfPosition;
out vec4 color;

void main() {
	color = vec4(colorOfPosition, 1.0);
}
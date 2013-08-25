#version 110

attribute vec4 position;
attribute vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

varying vec4 pip_color;

void main()
{
	gl_Position = projection * view * model * position;
	pip_color = color;
}

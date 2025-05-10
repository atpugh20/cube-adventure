#version 460 core
layout (location = 0) in vec4 a_Pos;
layout (location = 1) in vec4 a_Color;

out vec4 v_Color;

void main() {
	gl_Position = a_Pos;
	v_Color = a_Color;
}
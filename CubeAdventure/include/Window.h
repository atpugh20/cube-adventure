#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Macros.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "Shader.h"


class Window {
private:
	float Width;
	float Height;
	const char* Title;

	GLFWwindow* window;

public:
	Window(const float& width, const float& height, const char* title);
	~Window();
	
	void Init();

	GLFWwindow* GetWindow() const;

	float GetWidth() const;
	float GetHeight() const;
	const char* GetTitle() const;

};

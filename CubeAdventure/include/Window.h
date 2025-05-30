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
	
	double MouseX;
	double MouseY;

	GLFWwindow* window;

public:
	Window(const float& width	= 600.0f, 
		   const float& height  = 600.0f, 
		   const char* title	= "New Window");

	~Window();
	
	void Init();

	GLFWwindow* GetWindow() const;

	void UpdateMousePosition();

	double GetMouseX() const;
	double GetMouseY() const;

	float GetWidth() const;
	float GetHeight() const;
	const char* GetTitle() const;

};

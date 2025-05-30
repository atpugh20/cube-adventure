#pragma once

#include <vector>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Macros.h"
#include "Vertex.h"
#include "Window.h"

class Renderer {
private:
	std::vector<Vertex> Vertices;
	std::vector<int> Indices;

	VertexArray		*VAO;
	VertexBuffer	*VBO;
	ElementBuffer	*EBO;
	Shader			*shader;

public:
	Renderer(const char* vertex_path, const char* fragment_path);

	~Renderer();

	void Bind() const;
	void Unbind() const;

	void AddVertices(Vertex vertices[], int v_size, int indices[], int i_size);
	void ResetVertices();

	void Draw() const;

	void PrintVertices() const;
	void PrintIndices() const;

};

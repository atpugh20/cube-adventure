#include "Renderer.h"

Renderer::Renderer(const char* vertex_path, const char* fragment_path)
	: VAO(new VertexArray()),
      VBO(new VertexBuffer()),
	  EBO(new ElementBuffer()),
	  shader(new Shader(vertex_path, fragment_path))
{}

Renderer::~Renderer() {
	delete VAO;
	delete VBO; 
	delete EBO;
	delete shader;
}

void Renderer::Bind() const {
	VAO->Bind();
	VBO->Bind(Vertices.data(), Vertices.size() * sizeof(Vertex));
	EBO->Bind(Indices.data(), Indices.size() * sizeof(int));

	shader->Use();

	VBO->SetAttributes();
}

void Renderer::Unbind() const {
	VAO->Unbind();
	VBO->Unbind();
	EBO->Unbind();
}

void Renderer::AddVertices(Vertex vertices[], int v_size, int indices[], int i_size) {		
	int add_on = Vertices.size();

	for (int i = 0; i < v_size; i++) {
		Vertices.push_back(vertices[i]);
	}

	for (int i = 0; i < i_size; i++) {
		Indices.push_back(indices[i] + add_on);
	}
}

void Renderer::ResetVertices() {
	Vertices.clear();
	Indices.clear();
}

void Renderer::Draw() const {
	glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);
}

void Renderer::PrintVertices() const {
	for (const Vertex& v : Vertices) {
		print(v.position[0]);
		print(v.position[1]);
		print(v.position[2]);	
	}	
}

void Renderer::PrintIndices() const {
	for (int i : Indices) {
		print(i);
	}
}


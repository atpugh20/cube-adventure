#include "Macros.h"
#include "Window.h"
#include "Vertex.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "Shader.h"

#define print(x) std::cout << x << std::endl;

int main(void) {
    const float screen_width  = 256.0;
    const float screen_height = 240.0;
    const char* title = "Cube Adventure";

    const char *vertex_path   = "resources/shaders/vertex.shader";
    const char *fragment_path = "resources/shaders/fragment.shader";

    GLFWwindow *window = CreateWindow(screen_height, screen_height, title);
    
    Vertex vertices[] = {
        {{ 0.5f,  0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-0.5f, -0.5f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
    };

    int indices[] = {
        0, 1, 2
    };
    int index_count = sizeof(indices) / sizeof(int);
    
    VertexArray*   VAO = new VertexArray();
    VertexBuffer*  VBO = new VertexBuffer();
    ElementBuffer* EBO = new ElementBuffer();
    Shader *shader = new Shader(vertex_path, fragment_path);

    VAO->Bind();
    VBO->Bind(vertices, sizeof(vertices));
    EBO->Bind(indices, sizeof(indices));

    VBO->SetAttributes();

    // Unbind all vertex objects before first render 
    /*VAO->Unbind();
    VBO->Unbind();
    EBO->Unbind();*/

    shader->Use();
 
    // Main Draw Loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader->Use();

        VAO->Bind();
        VBO->Rebind(vertices, sizeof(vertices));

        glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete VAO;
    delete VBO;
    delete EBO;

    glfwTerminate();
    return 0;
}
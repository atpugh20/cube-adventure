#include "Macros.h"
#include "Window.h"

#define print(x) std::cout << x << std::endl;

int main(void) {
    const float screen_width  = 256.0;
    const float screen_height = 240.0;
    const char* title = "Cube Adventure";

    GLFWwindow *window = CreateWindow(screen_height, screen_height, title);

    float vertices[] = {
        0.5f,  0.5f,
       -0.5f, -0.5f,
        0.5f, -0.5f,
    };

    int indices[] = {
        0, 1, 2
    };
    
    // Vertex Array
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertex Buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element Buffer
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Vertex attributes

    // Source Shaders

    // Compile Shaders

    // Attach to program

    // Delete Shaders
        
    // Main Draw Loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
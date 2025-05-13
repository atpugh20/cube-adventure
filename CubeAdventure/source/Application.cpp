#include "Macros.h"
#include "Window.h"
#include "Vertex.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "Shader.h"

#include "Player.h"

#define print(x) std::cout << x << std::endl;

int main(void) {
    const float screen_width  = 600.0f;
    const float screen_height = 600.0f;
    const char* title = "Cube Adventure";

    const char *vertex_path   = "resources/shaders/vertex.shader";
    const char *fragment_path = "resources/shaders/fragment.shader";

    GLFWwindow *window = CreateWindow(screen_height, screen_height, title);

    Player player = Player(0.1f);
   
    int index_count = sizeof(player.indices) / sizeof(int);
    
    VertexArray*   VAO = new VertexArray();
    VertexBuffer*  VBO = new VertexBuffer();
    ElementBuffer* EBO = new ElementBuffer();
    Shader *shader = new Shader(vertex_path, fragment_path);

    VAO->Bind();
    VBO->Bind(player.vertices, sizeof(player.vertices));
    EBO->Bind(player.indices, sizeof(player.indices));

    VBO->SetAttributes();

    // Unbind all vertex objects before first render 
    VAO->Unbind();
    VBO->Unbind();
    EBO->Unbind();

    shader->Use();

    player.Vel = Vec3(0.0001, 0, 0);
 
    // Main Draw Loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        player.Update();
        print(player.vertices[0].position[0]);

        shader->Use();

        VAO->Bind();
        VBO->Rebind(player.vertices, sizeof(player.vertices));

        glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete VAO;
    delete VBO;
    delete EBO;
    delete shader;

    glfwTerminate();
    return 0;
}
#include "Application.h"

void Application::Run() {

	Window window = Window(ScreenWidth, ScreenHeight, WindowTitle);

    Player player = Player(0.1f);
   
    int index_count = sizeof(player.indices) / sizeof(int);
    
    VertexArray*   VAO = new VertexArray();
    VertexBuffer*  VBO = new VertexBuffer();
    ElementBuffer* EBO = new ElementBuffer();
    Shader *shader = new Shader(VertexPath, FragmentPath);

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
    while (!glfwWindowShouldClose(window.GetWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);

        player.Update();
        print(player.vertices[0].position[0]);

        shader->Use();

        VAO->Bind();
        VBO->Rebind(player.vertices, sizeof(player.vertices));

        glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.GetWindow());
        glfwPollEvents();
    }

    delete VAO;
    delete VBO;
    delete EBO;
    delete shader;

    glfwTerminate();
}
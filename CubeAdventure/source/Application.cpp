#include "Application.h"


Application::Application() 
	: DeltaTime(0.0f),
	  LastFrameTime(0.0f),

      ScreenWidth(600.0f), 
      ScreenHeight(600.0f), 
      WindowTitle("Cube Adventure"), 

      VertexPath("resources/shaders/vertex.shader"), 
	  FragmentPath("resources/shaders/fragment.shader") 
{}

void Application::Run() {
	Window* window = new Window(ScreenWidth, ScreenHeight, WindowTitle);
	Renderer *renderer = new Renderer(VertexPath, FragmentPath);

    Player player = Player(0.05f);
    Player player2 = Player(0.05f, 0.5, 0.5, 0);
    
	int v_size = sizeof(player.vertices) / sizeof(player.vertices[0]);
	int i_size = sizeof(player.indices) / sizeof(player.indices[0]);
	renderer->AddVertices(player.vertices, v_size, player.indices, i_size);
    
    v_size = sizeof(player2.vertices) / sizeof(player2.vertices[0]);
	i_size = sizeof(player2.indices) / sizeof(player2.indices[0]);
	renderer->AddVertices(player2.vertices, v_size, player2.indices, i_size);
   
    renderer->Bind();
    renderer->Unbind();

    // Main Draw Loop
    while (!glfwWindowShouldClose(window->GetWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        window->UpdateMousePosition();

        renderer->ResetVertices();

        player.UpdatePosition();
		v_size = sizeof(player.vertices) / sizeof(player.vertices[0]);
		i_size = sizeof(player.indices) / sizeof(player.indices[0]);
		renderer->AddVertices(player.vertices, v_size, player.indices, i_size);

		player2.SetPosition(window->GetMouseX(), window->GetMouseY(), 0.0f);
		player2.UpdatePosition();
		v_size = sizeof(player2.vertices) / sizeof(player2.vertices[0]);
		i_size = sizeof(player2.indices) / sizeof(player2.indices[0]);
		renderer->AddVertices(player2.vertices, v_size, player2.indices, i_size);
    
        print(player2.GetX());
		print(player.GetX());

        renderer->Bind();
        renderer->Draw();

        glfwSwapBuffers(window->GetWindow());
        glfwPollEvents();
    }
    
    delete renderer;
	delete window;
}
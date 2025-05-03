#include "Macros.h"
#include "Window.h"
#include "Vec2.h"

#define print(x) std::cout << x << std::endl;

int main(void) {
    const float screen_width  = 256.0;
    const float screen_height = 240.0;
    const char* title = "Cube Adventure";

    GLFWwindow *window = CreateWindow(screen_height, screen_height, title);

    Vec2 position = Vec2(1, 2);

    print(position.GetX());
    print(position.GetY());
    print(position.GetMagnitude());

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
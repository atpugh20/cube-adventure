#include "Window.h"


GLFWwindow *CreateWindow(const float &width, const float &height, const char *title) {
    /**
     * Initializes a window using GLFW and GLAD
     * then returns it to be used by the render loop.
     */
    GLFWwindow *window;

    // Initialize GLFw 
    if (!glfwInit()) {
        print("Cannot initialize GLFW.");
        return nullptr;
    }
    
    // Create window
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        print("Could not create window");
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        print("Failed to initilize GLAD");
        return nullptr;
    }
    
    return window;
}
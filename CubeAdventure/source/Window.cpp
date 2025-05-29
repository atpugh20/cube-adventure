#include "Window.h"

Window::Window(const float &width, const float &height, const char *title)
: Width(width), Height(height), Title(title) {
    Init();
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::Init() {
    /**
	 * Initializes the GLFW window and sets up GLAD.
     */

	// Initialize GLFw 
    if (!glfwInit())
        print("Cannot initialize GLFW.");
    
    // Create window
    window = glfwCreateWindow(Width, Height, Title, NULL, NULL);

    if (!window) {
        print("Could not create window");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
        print("Failed to initilize GLAD");   
 
}

GLFWwindow *Window::GetWindow() const { return window; }

float Window::GetWidth() const { return Width; }
float Window::GetHeight() const { return Height; }
const char* Window::GetTitle() const { return Title; }

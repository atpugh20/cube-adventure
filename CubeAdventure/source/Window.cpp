#include "Window.h"

Window::Window(const float &width, const float &height, const char *title)
: Width(width), Height(height), Title(title), window(nullptr) {
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

void Window::UpdateMousePosition() {
    glfwGetCursorPos(glfwGetCurrentContext(), &MouseX, &MouseY);

	// Invert Y coordinate to match OpenGL's coordinate system
	MouseX =  (MouseX - Width  / 2);
	MouseY = -(MouseY - Height / 2);

    print(MouseX);
}

GLFWwindow *Window::GetWindow() const { return window; }
    
double Window::GetMouseX() const { return MouseX; }
double Window::GetMouseY() const { return MouseY; }

float Window::GetWidth() const { return Width; }
float Window::GetHeight() const { return Height; }

const char* Window::GetTitle() const { return Title; }

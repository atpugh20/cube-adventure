#pragma once

#include "Macros.h"
#include "Window.h"
#include "Vertex.h"


#include "Player.h"


class Application {
private:
	float DeltaTime;

	float ScreenWidth;
	float ScreenHeight;
	const char* WindowTitle;

	const char* VertexPath;
	const char* FragmentPath;

public:
	Application() {
		ScreenWidth = 600.0f;
		ScreenHeight = 600.0f;
		WindowTitle = "Cube Adventure";

		VertexPath   = "resources/shaders/vertex.shader";
		FragmentPath = "resources/shaders/fragment.shader";
	}
	void Run();
};

#pragma once

#include "Macros.h"
#include "Window.h"
#include "Vertex.h"
#include "Renderer.h"

#include "Player.h"


class Application {
private:
	float DeltaTime;
	float LastFrameTime;

	float ScreenWidth;
	float ScreenHeight;
	const char* WindowTitle;

	const char* VertexPath;
	const char* FragmentPath;

public:
	Application();
		
	void Run();
};

#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

namespace tinyengine
{
	class TinyEngine
	{
	public:
		TinyEngine();
		TinyEngine(int screen_width,int screen_height, bool isBlendEnabled, bool isDepthTestEnabled,bool isStencilTestEnabled, GLenum blendFuncSrc,
			GLenum blendFuncDst);
		void Init();
		void MainLoop();
	private:
		void GetInput();
		void Update();
		void Render();
		int SCREEN_WIDTH, SCREEN_HEIGHT;
		bool isBlendEnabled, isDepthTestEnabled, isStencilTestEnabled;
		GLenum blendFuncSrc, blendFuncDst;
		GLFWwindow* window;
	};

}
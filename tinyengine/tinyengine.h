#pragma once

#include <iostream>
#include <vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Input/Input.h"
#include "Gameobject/Gameobject.h"

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
		void AddGameobject(Gameobject& gameobject);
	private:
		void GetInput();
		void Update();
		void Render();
		int SCREEN_WIDTH, SCREEN_HEIGHT;
		bool isBlendEnabled, isDepthTestEnabled, isStencilTestEnabled;
		GLenum blendFuncSrc, blendFuncDst;
		GLFWwindow* window;
		std::vector<Gameobject> gameobjects;
	};

}
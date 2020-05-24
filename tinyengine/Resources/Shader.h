#pragma once

#include "GL/glew.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace tinyengine
{
	class Shader
	{
	public:
		Shader() = default;
		Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		unsigned int ID;
		void Use();
	private:
		void CompileShader(const std::string& vertexString,const std::string& fragmentString);
	
	};
}
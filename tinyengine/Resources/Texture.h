#pragma once

#include <string>
#include "../stb/stb_image.h"
#include "GL/glew.h"
#include <iostream>

namespace tinyengine
{
	class Texture
	{
	public:
		Texture() = default;
		Texture(std::string textureFilePath, GLenum internalFormat, GLenum format,
			GLenum wrapS, GLenum wrapT, GLenum filterMin, GLenum filterMax);
		unsigned int ID;
		unsigned char* data;
		int width, height, fileChannels;
		unsigned int internalFormat, format;
		unsigned int wrapS, wrapT;
		unsigned int filterMin;
		unsigned int filterMax;
		
	};
}
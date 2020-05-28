#include "Texture.h"

namespace tinyengine
{
	Texture::Texture(std::string textureFilePath, GLenum internalFormat, GLenum format,
		GLenum wrapS, GLenum wrapT, GLenum filterMin, GLenum filterMax)
	{
		data = stbi_load(textureFilePath.c_str(), &this->width, &this->height, &fileChannels, 0);

		glGenTextures(1, &this->ID);
		glBindTexture(GL_TEXTURE_2D, this->ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMax);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		else
		{
			std::cout << "Texture cannot be loaded!" << std::endl;
		}

	}
}
			
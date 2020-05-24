#include "Shader.h"

namespace tinyengine
{
	Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
	{
		std::ifstream vertexFile;
		std::ifstream fragmentFile;

		vertexFile.open(vertexShaderPath);
		fragmentFile.open(fragmentShaderPath);

		if (!vertexFile)
		{
			std::cout << "Vertex shader file cannot be opened!" << std::endl;
			return;
		}

		if (!fragmentFile)
		{
			std::cout << "Fragment shader file cannot be opened!" << std::endl;
			return;
		}

		std::stringstream vertexStringStream;
		vertexStringStream << vertexFile.rdbuf();
		std::stringstream fragmentStringStream;
		fragmentStringStream << fragmentFile.rdbuf();

		vertexFile.close();
		fragmentFile.close();

		std::string vertexString = vertexStringStream.str();
		std::string fragmentString = fragmentStringStream.str();

		CompileShader(vertexString, fragmentString);


	}

	void tinyengine::Shader::Use()
	{
		glUseProgram(this->ID);
	}

	void Shader::CompileShader(const std::string& vertexString, const std::string& fragmentString)
	{
		const char* vertexCode = vertexString.c_str();
		const char* fragmentCode = fragmentString.c_str();

		unsigned int vertexShader, fragmentShader;

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexCode, NULL);
		glCompileShader(vertexShader);

		int compileResult;
		char log[1024];

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileResult);
		if (!compileResult)
		{
			glGetShaderInfoLog(vertexShader, 1024, NULL, log);
			std::cout << "Vertex shader compile error : \n" << log << std::endl;
		}

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileResult);
		if (!compileResult)
		{
			glGetShaderInfoLog(fragmentShader, 1024, NULL, log);
			std::cout << "Fragment shader compile error : \n" << log << std::endl;
		}

		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);

		glLinkProgram(ID);

		glGetShaderiv(ID, GL_LINK_STATUS, &compileResult);
		if (!compileResult)
		{
			glGetShaderInfoLog(ID, 1024, NULL, log);
			std::cout << "Shader link error : \n" << log << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}


}

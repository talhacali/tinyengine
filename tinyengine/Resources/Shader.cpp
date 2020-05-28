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

	void tinyengine::Shader::Use()
	{
		glUseProgram(this->ID);
	}

	void tinyengine::Shader::SetBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

	void tinyengine::Shader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void tinyengine::Shader::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

	void tinyengine::Shader::SetVec2(const std::string& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}

	void tinyengine::Shader::SetVec2(const std::string& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
	}

	void tinyengine::Shader::SetVec3(const std::string& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}

	void tinyengine::Shader::SetVec3(const std::string& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
	}

	void tinyengine::Shader::SetVec4(const std::string& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	void tinyengine::Shader::SetVec4(const std::string& name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
	}

	void tinyengine::Shader::SetMat2(const std::string& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	void tinyengine::Shader::SetMat3(const std::string& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	void tinyengine::Shader::SetMat4(const std::string& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}


}

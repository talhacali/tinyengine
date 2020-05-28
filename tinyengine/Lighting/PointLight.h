#pragma once

#include <vector>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../Resources/Shader.h"
#include "../Camera/FlyCamera.h"

namespace tinyengine
{
	class PointLight
	{
	public:
		PointLight() = default;
		PointLight(const Shader& shader, const glm::vec3& position, const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular,
			float constant, float linear, float quadratic, std::shared_ptr<Camera> camera);

		void Init();
		void Render();

		Shader shader;
		glm::vec3 position;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;

		float constant;
		float linear;
		float quadratic;

		std::shared_ptr<Camera> camera;

	private:

		unsigned int VBO, VAO;
		std::vector<float> vertices;
	};
}
#pragma once

#include "../glm/glm.hpp"
#include "../Resources/Shader.h"

namespace tinyengine
{
	class DirectionalLight
	{
	public:
		DirectionalLight() = default;
		DirectionalLight(const glm::vec3& direction, const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular):
			direction(direction),ambient(ambient),diffuse(diffuse),specular(specular){}

		glm::vec3 direction;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};
}
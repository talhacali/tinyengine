#pragma once
#include "Texture.h"
#include "Shader.h"
#include "../Lighting/DirectionalLight.h"
#include "../Lighting/PointLight.h"
#include "../glm/glm.hpp"
#include <vector>

#define MAX_NR_POINT_LIGHTS 32

namespace tinyengine
{
	class Material
	{
	public:
		Material();
		Material(const Shader& shader,const Texture& diffuseMap, const Texture& specularMap, const DirectionalLight& dirLight,
			std::vector<PointLight> pointLights, float shininess);

		Shader shader;
		Texture diffuseMap;
		Texture specularMap;
		float shininess;

		DirectionalLight dirLight;
		std::vector<PointLight> pointLights;

	};
}

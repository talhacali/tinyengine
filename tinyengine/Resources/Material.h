#pragma once
#include "Texture.h"
#include "Shader.h"
#include "../Lighting/DirectionalLight.h"
#include "../Lighting/PointLight.h"
#include "../glm/glm.hpp"

#define MAX_NR_POINT_LIGHTS 32

namespace tinyengine
{
	class Material
	{
	public:
		Material();
		Material(const Texture& texture, const Shader& shader,const Texture& diffuseMap, const Texture& specularMap, const DirectionalLight& dirLight,
			int number_of_point_lights, PointLight* pointLights);

		Texture texture;
		Shader shader;

		Texture diffuseMap;
		Texture specularMap;

		DirectionalLight dirLight;
		int number_of_point_lights;
		PointLight *pointLights;
	};
}

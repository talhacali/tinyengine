#include "Material.h"

namespace tinyengine
{
	Material::Material()
	{
	}
	Material::Material(const Texture& texture, const Shader& shader, const Texture& diffuseMap, const Texture& specularMap, const DirectionalLight& dirLight,
		int number_of_point_lights, PointLight* pointLights)
	{
		this->texture = texture;
		this->shader = shader;
		this->diffuseMap = diffuseMap;
		this->specularMap = specularMap;
		this->dirLight = dirLight;
		this->number_of_point_lights = number_of_point_lights;
		this->pointLights = pointLights;
	}
}
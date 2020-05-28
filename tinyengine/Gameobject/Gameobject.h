#pragma once

#include <string>
#include <memory>

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../Resources/Texture.h"
#include "../Resources/Material.h"
#include "../Camera/Camera.h"
#include "../Camera/FlyCamera.h"

namespace tinyengine
{
	class Gameobject
	{
	public:
		Gameobject() = default;
		Gameobject(glm::vec3 position, glm::vec3 rotation, float angle, std::string name,Material &material,std::vector<float> vertices,float persWidth,float persHeight,
			std::shared_ptr<Camera> camera, void (*externalupdate)(Gameobject* gameobject));
		Gameobject(glm::vec3 position, glm::vec3 rotation, float angle, std::string name, Material& material, float persWidth, float persHeight,
			std::shared_ptr<Camera> camera, void (*externalupdate)(Gameobject* gameobject));
		void Init();
		void Update();
		void Render();

		std::shared_ptr<Camera> camera;
		glm::vec3 position, rotation;
		float angle;
		std::string name;
		Material material;
		unsigned int VBO, VAO;
		std::vector<float> vertices;
		float persWidth, persHeight;
	private:
		void (*update)(Gameobject *gameobject);
	};

}
		
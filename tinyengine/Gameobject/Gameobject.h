#pragma once

#include <string>

#include "../glm/glm.hpp"
#include "../Resources/Texture.h"

namespace tinyengine
{
	class Gameobject
	{
	public:
		Gameobject(glm::vec3 position, glm::vec3 rotation, std::string name,Texture &texture,void (*externalupdate)(Gameobject* gameobject));
		void Update();
		void Render();

		glm::vec3 position, rotation;
		std::string name;
		Texture texture;
	private:
		void (*update)(Gameobject *gameobject);
	};

}
		
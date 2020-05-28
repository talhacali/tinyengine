#pragma once

#include "../glm/glm.hpp"
#include "Gameobject.h"

#include <memory>

namespace tinyengine
{
	class Cube : public Gameobject
	{
	public:
		Cube(glm::vec3 position, glm::vec3 rotation,float angle, std::string name, Material& material, float persWidth, float persHeight,
			std::shared_ptr<Camera> camera, void (*externalupdate)(Gameobject* gameobject));
		void Init();
		//float vertices[288];
	private:
		
	};
}
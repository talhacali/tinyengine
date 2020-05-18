#include "Gameobject.h"

namespace tinyengine
{
	Gameobject::Gameobject(glm::vec3 position, glm::vec3 rotation, std::string name, Texture& texture, void(*externalupdate)(Gameobject *gameobject))
	{
		this->position = position;
		this->rotation = rotation;
		this->name = name;
		this->texture = texture;
		this->update = externalupdate;
	}

	void Gameobject::Update()
	{
		update(this);
	}

	void Gameobject::Render()
	{

	}

}

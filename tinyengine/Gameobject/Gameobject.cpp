#include "Gameobject.h"

namespace tinyengine
{
	Gameobject::Gameobject(glm::vec3 position, glm::vec3 rotation, float angle, std::string name, Material& material,std::vector<float> vertices,
        float persWidth, float persHeight, std::shared_ptr<Camera> camera,void(*externalupdate)(Gameobject *gameobject))
	{
		this->position = position;
		this->rotation = rotation;
        this->angle = angle;
		this->name = name;
		this->material = material;
		this->update = externalupdate;
		this->vertices = vertices;
        this->camera = camera;
        this->persWidth = persWidth;
        this->persHeight = persHeight;
        
	}

	Gameobject::Gameobject(glm::vec3 position, glm::vec3 rotation, float angle, std::string name, Material& material,
        float persWidth, float persHeight, std::shared_ptr<Camera> camera, void(*externalupdate)(Gameobject* gameobject))
	{
		this->position = position;
		this->rotation = rotation;
        this->angle = angle;
		this->name = name;
		this->material = material;
		this->update = externalupdate;
        this->camera = camera;
        this->persWidth = persWidth;
        this->persHeight = persHeight;

	}


	void Gameobject::Init()
	{
		
	}

	void Gameobject::Update()
	{
		update(this);
	}

	void Gameobject::Render()
	{
        material.shader.Use();

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), this->persWidth / this->persHeight, 0.1f, 100.0f);
        
        glm::mat4 view = (*camera).GetViewMatrix();

        material.shader.SetMat4("projection", projection);
        material.shader.SetMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, this->position);
        model = glm::rotate(model, glm::radians(this->angle), this->rotation);
        material.shader.SetMat4("model", model);
        
        material.shader.SetVec3("viewPos", (*camera).position);
        material.shader.SetFloat("material.shininess", material.shininess);

        material.shader.SetVec3("dirLight.direction", material.dirLight.direction);
        material.shader.SetVec3("dirLight.ambient", material.dirLight.ambient);
        material.shader.SetVec3("dirLight.diffuse", material.dirLight.diffuse);
        material.shader.SetVec3("dirLight.specular", material.dirLight.specular);

        material.shader.SetInt("nr_active_point_lights", material.pointLights.size());

        for (int i = 0; i < material.pointLights.size(); i++)
        {
            std::string lightname = "pointLights[" + std::to_string(i) + "].";
            material.shader.SetVec3(lightname + "position", material.pointLights[i].position);
            material.shader.SetVec3(lightname + "ambient", material.pointLights[i].ambient);
            material.shader.SetVec3(lightname + "diffuse", material.pointLights[i].diffuse);
            material.shader.SetVec3(lightname + "specular", material.pointLights[i].specular);
            material.shader.SetFloat(lightname + "constant", material.pointLights[i].constant);
            material.shader.SetFloat(lightname + "linear", material.pointLights[i].linear);
            material.shader.SetFloat(lightname + "quadratic", material.pointLights[i].quadratic);
        }

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, material.diffuseMap.ID);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, material.specularMap.ID);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 36);
       
	}

}

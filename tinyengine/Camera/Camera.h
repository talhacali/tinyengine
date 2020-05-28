#pragma once

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"

namespace tinyengine
{
	enum class CAMERA_MOVE_DIRECTION
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	enum class CAMERA_ROTATE_DIRECTION
	{
		ROLL,
		PITCH,
		YAW
	};

	class Camera
	{
	public:
		virtual glm::mat4 GetViewMatrix() = 0;
		virtual void Move(CAMERA_MOVE_DIRECTION direction,float speed,float deltaTime) = 0;
		virtual void Rotate(CAMERA_ROTATE_DIRECTION direction, float offset) = 0;
		glm::vec3 position;
	protected:
		glm::vec3 frontVector;
		glm::vec3 upVector;
		glm::vec3 worldUpVector = glm::vec3(0.0f,1.0f,0.0f);
		glm::vec3 rightVector;
		float yaw = -90.0f;
		float pitch = 0.0f;

		virtual void UpdateCamera() = 0;
		
	};
}
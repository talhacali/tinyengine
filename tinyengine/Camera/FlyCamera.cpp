#include "FlyCamera.h"

namespace tinyengine
{
	FlyCamera::FlyCamera(const glm::vec3& position)
	{
		this->position = position;

		UpdateCamera();
	}

	glm::mat4 FlyCamera::GetViewMatrix()
	{
		return glm::lookAt(position, position + frontVector, upVector);
	}

	void FlyCamera::Move(CAMERA_MOVE_DIRECTION direction, float speed, float deltaTime)
	{
		float velocity = speed * deltaTime;

		if (direction == CAMERA_MOVE_DIRECTION::FORWARD)
		{
			this->position += frontVector * velocity;
		}
		else if (direction == CAMERA_MOVE_DIRECTION::BACKWARD)
		{
			this->position -= frontVector * velocity;
		}
		else if (direction == CAMERA_MOVE_DIRECTION::RIGHT)
		{
			this->position += rightVector * velocity;
		}
		else if (direction == CAMERA_MOVE_DIRECTION::LEFT)
		{
			this->position -= rightVector * velocity;
		}

	}

	void FlyCamera::Rotate(CAMERA_ROTATE_DIRECTION direction, float offset)
	{
		if (direction == CAMERA_ROTATE_DIRECTION::PITCH)
		{
			pitch += offset;
		}
		else if (direction == CAMERA_ROTATE_DIRECTION::YAW)
		{
			yaw += offset;
		}
		else if (direction == CAMERA_ROTATE_DIRECTION::ROLL)
		{

		}

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		UpdateCamera();
	}

	void FlyCamera::UpdateCamera()
	{
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		this->frontVector = glm::normalize(front);
		this->rightVector = glm::normalize(glm::cross(this->frontVector, this->worldUpVector));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		this->upVector = glm::normalize(glm::cross(this->rightVector, this->frontVector));
	}
}
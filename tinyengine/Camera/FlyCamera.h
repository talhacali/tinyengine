#pragma once

#include "Camera.h"

namespace tinyengine
{
	class FlyCamera : public Camera
	{
	public:
		FlyCamera() {};
		FlyCamera(const glm::vec3& position);
		glm::mat4 GetViewMatrix();
		void Move(CAMERA_MOVE_DIRECTION direction, float speed, float deltaTime);
		void Rotate(CAMERA_ROTATE_DIRECTION direction, float offset);
	private:
		void UpdateCamera();
	};
}
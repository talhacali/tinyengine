#pragma once

#include <iostream>
#include <map>

namespace tinyengine
{
	enum class InputKeys
	{
		KEY_W = 87,
		KEY_A = 65,
		KEY_S = 83,
		KEY_D = 68,
		KEY_SPACE = 32,
		KEY_ESCAPE = 256
	};

	class Input
	{
	public:
		static bool GetKeyPressed(InputKeys key);
		static void SetKeyPressed(InputKeys key, bool pressed);
		static float lastXPos;
		static float lastYPos;
		static float xPos,yPos;
		static float xOffset, yOffset;
	private:
		static std::map<InputKeys, bool> keysPressed;
	};
}

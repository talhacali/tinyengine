#include "Input.h"

namespace tinyengine
{
	std::map<InputKeys, bool> Input::keysPressed = { {InputKeys::KEY_W,false},{InputKeys::KEY_A,false},{InputKeys::KEY_S,false},
													{InputKeys::KEY_D,false},{InputKeys::KEY_SPACE,false},{InputKeys::KEY_ESCAPE,false} };

	bool Input::GetKeyPressed(InputKeys key)
	{
		return keysPressed[key];
	}
	void Input::SetKeyPressed(InputKeys key,bool pressed)
	{
		keysPressed[key] = pressed;
	}
}
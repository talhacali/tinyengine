#include "Input.h"

namespace
{
	bool Input::GetKeyPressed(InputKeys key)
	{
		return keysPressed[key];
	}
}
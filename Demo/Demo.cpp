#include <iostream>
#include "tinyengine.h"

using namespace tinyengine;

/*
    A basic demo game to show the capabilities of tinyengine.
*/

void Update(Gameobject* gameobject);

int main()
{
    TinyEngine engine;

    engine.Init();
    
    glm::vec3 position(1.0f), rotation(1.0f);
    Texture texture;
    Gameobject gameobject(position, rotation, "gameobject", (Texture&)texture, &Update);
    
    engine.AddGameobject(gameobject);
    
    engine.MainLoop();

}

void Update(Gameobject *gameobject)
{

}
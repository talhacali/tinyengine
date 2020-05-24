#include <iostream>
#include "tinyengine.h"
#include "Resources/Shader.h"

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
   
    Shader shader("..\\tinyengine\\Shaders\\vertex_shader.glsl", "..\\tinyengine\\Shaders\\fragment_shader.glsl");

    Material material;
    Gameobject gameobject(position, rotation, "gameobject", material, &Update);
    
    engine.AddGameobject(gameobject);
    
    engine.MainLoop();

}

void Update(Gameobject *gameobject)
{

}
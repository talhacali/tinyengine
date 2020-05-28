#include <iostream>
#include <vector>
#include "tinyengine.h"
#include "Resources/Shader.h"
#include "Resources/Texture.h"
#include "Gameobject/Cube.h"
#include "Lighting/DirectionalLight.h"
#include "Lighting/PointLight.h"
#include "Camera/Camera.h"
#include "Camera/FlyCamera.h"

using namespace tinyengine;

/*
    A basic demo game to show the capabilities of tinyengine.
*/

void Update(Gameobject* gameobject);

float Input::xPos;
float Input::yPos;
float Input::lastXPos;
float Input::lastYPos;
float Input::xOffset;
float Input::yOffset;

int main()
{
    TinyEngine engine;

    engine.Init();
    
    glm::vec3 position(0.0f, 1.0f, -5.0f) , rotation(0.0f, 0.0f, 1.0f);
    glm::vec3 direction(-0.2f, -1.0f, -0.3f);
    glm::vec3 ambient(0.05f, 0.05f, 0.05f);
    glm::vec3 diffuse(0.4f, 0.4f, 0.4f);
    glm::vec3 specular(0.5f, 0.5f, 0.5f);
   
    Shader shader("..\\tinyengine\\Shaders\\vertex_shader.glsl", "..\\tinyengine\\Shaders\\fragment_shader.glsl");
    Shader shaderLightSource("..\\tinyengine\\Shaders\\light_vertex_shader.glsl", "..\\tinyengine\\Shaders\\light_fragment_shader.glsl");
    Texture diffuseMap("..\\tinyengine\\Textures\\container2.png", GL_RGB, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    Texture specularMap("..\\tinyengine\\Textures\\container2_specular.png", GL_RGB, GL_RGBA, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    DirectionalLight dirLight(direction, ambient, diffuse, specular);

    glm::vec3 pointLightPositions[] = {
    glm::vec3(0.5f, 0.2f, -1.0f),
    glm::vec3(-2.0f,  1.0f, -5.0f),
    };

    std::shared_ptr<Camera> flyCamera = std::make_shared<FlyCamera>(glm::vec3(0.0f, 0.0f, 3.0f));

    PointLight pointLight(shaderLightSource, pointLightPositions[0], ambient, diffuse, specular, 1.0f, 0.09f, 0.032f,flyCamera);
    PointLight pointLight1(shaderLightSource, pointLightPositions[1], ambient, diffuse, specular, 1.0f, 0.09f, 0.032f,flyCamera);

    pointLight.Init();
    pointLight1.Init();

    std::vector<PointLight> pointLights;

    pointLights.push_back(pointLight);
    pointLights.push_back(pointLight1);

    Material material(shader,diffuseMap,specularMap,dirLight,pointLights,2.0f);
    
    Cube cube(position, rotation,2.0f, "cube", material,1920.0f,1080.0f,flyCamera, &Update);
    
    cube.Init();

    engine.AddGameobject(cube);

    engine.AddPointLight(pointLight);
    engine.AddPointLight(pointLight1);

    engine.MainLoop();

}

bool isChanged = false;

void Update(Gameobject *gameobject)
{
    if (Input::GetKeyPressed(InputKeys::KEY_W))
    {
        gameobject->camera->Move(CAMERA_MOVE_DIRECTION::FORWARD, 2.5f, Time::deltaTime);
    }

    if (Input::GetKeyPressed(InputKeys::KEY_S))
    {
        gameobject->camera->Move(CAMERA_MOVE_DIRECTION::BACKWARD, 2.5f, Time::deltaTime);
    }

    if (Input::GetKeyPressed(InputKeys::KEY_A))
    {
        gameobject->camera->Move(CAMERA_MOVE_DIRECTION::LEFT, 2.5f, Time::deltaTime);
    }

    if (Input::GetKeyPressed(InputKeys::KEY_D))
    {
        gameobject->camera->Move(CAMERA_MOVE_DIRECTION::RIGHT, 2.5f, Time::deltaTime);
    }

    float sensitivity = 0.4f;

    if (Input::xPos >= 1900.0f)
    {
        gameobject->camera->Rotate(CAMERA_ROTATE_DIRECTION::YAW, sensitivity);
    }

    if (Input::xPos <= 10.0f)
    {
        gameobject->camera->Rotate(CAMERA_ROTATE_DIRECTION::YAW, -sensitivity);
    }
    
    if (Input::yPos >= 1000.0f)
    {
        gameobject->camera->Rotate(CAMERA_ROTATE_DIRECTION::PITCH, -sensitivity);
    }

   if (Input::yPos <= 10.0f)
    {
        gameobject->camera->Rotate(CAMERA_ROTATE_DIRECTION::PITCH, sensitivity);
    }
    
}
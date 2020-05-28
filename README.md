# tinyengine

tinyengine is a small and naive game engine that I developed with OpenGL. It can be added as a static library to your solutions. 
I used glm as math library, stb as image loading library for textures, assimp as model loading library, GLFW as window and OpenGL context library and GLEW as OpenGL wrapper. C++ version is C++14.

I am developing a very simple game to demonstrate the capabilities of tinyengine. It is included in the solution as a project named Demo.
It is a simple game with a fly like camera and a couple of objects in the scene.

## Features
- Phong lighting with directional and point light source support.
- Material support with diffuse and specular light support.
- Input system with keyboard and mouse.
- General camera and fly like camera that is derived from it.

## Work-in-progress
- Model loading support.
- Spotlight support.
- Custom shader support.

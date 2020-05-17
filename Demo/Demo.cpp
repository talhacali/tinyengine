#include <iostream>
#include "tinyengine.h"

using namespace tinyengine;

/*
    A basic demo game to show the capabilities of tinyengine.
*/

int main()
{
    TinyEngine engine;

    engine.Init();
    
    engine.MainLoop();

}

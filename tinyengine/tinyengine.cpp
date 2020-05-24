#include "tinyengine.h"


namespace tinyengine
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	TinyEngine::TinyEngine() : SCREEN_WIDTH(1920),SCREEN_HEIGHT(1080),isBlendEnabled(false),isDepthTestEnabled(true),isStencilTestEnabled(false),
        blendFuncSrc(GL_SRC_ALPHA),blendFuncDst(GL_ONE_MINUS_SRC_ALPHA), window(nullptr)
	{
	}

    TinyEngine::TinyEngine(int screen_width, int screen_height,bool isBlendEnabled, bool isDepthTestEnabled, bool isStencilTestEnabled, GLenum blendFuncSrc,
        GLenum blendFuncDst) : SCREEN_WIDTH(screen_width), SCREEN_HEIGHT(screen_height), isBlendEnabled(isBlendEnabled),
        isDepthTestEnabled(isDepthTestEnabled), isStencilTestEnabled(isStencilTestEnabled), blendFuncSrc(blendFuncSrc), blendFuncDst(blendFuncDst),
        window(nullptr)
    {

    }

	void TinyEngine::Init()
	{
        glfwInit();
       /* glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);*/

        glfwWindowHint(GLFW_RESIZABLE, false);

        window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tinyengine", nullptr, nullptr);
        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK)
            std::cout << "Error!" << std::endl;

        std::cout << glGetString(GL_VERSION) << std::endl;
                                                             
        glfwSetKeyCallback(window, key_callback);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        if (isBlendEnabled)
        {
            glEnable(GL_BLEND);
            glBlendFunc(blendFuncSrc, blendFuncDst);
        }
            
        if (isDepthTestEnabled)
            glEnable(GL_DEPTH_TEST);

        if (isStencilTestEnabled)
            glEnable(GL_STENCIL_TEST);

        //Init components

       
	}
    void TinyEngine::MainLoop()
    {
        if (window == nullptr)
        {
            std::cout << "Window is not initialized, run init function first!" << std::endl;
            return;
        }

        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        while (!glfwWindowShouldClose(window))
        {
            // calculate delta time
            // --------------------
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            glfwPollEvents();

            Update();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            
            Render();

            glfwSwapBuffers(window);
        }

        // delete components

        glfwTerminate();
    }

    void TinyEngine::AddGameobject(Gameobject& gameobject)
    {
        gameobjects.push_back(gameobject);
    }

    void TinyEngine::Update()
    {
        for (std::vector<Gameobject>::iterator itr = gameobjects.begin(); itr != gameobjects.end(); itr++)
        {
            (*itr).Update();
        }

    }

    void TinyEngine::Render()
    {
        for (std::vector<Gameobject>::iterator itr = gameobjects.begin(); itr != gameobjects.end(); itr++)
        {
            (*itr).Render();
        }
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        if (key >= 0 && key < 1024)
        {
            if (action == GLFW_PRESS)
                Input::SetKeyPressed((InputKeys)key, true);
            else if (action == GLFW_RELEASE)
                Input::SetKeyPressed((InputKeys)key, false);
        }
    }

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}


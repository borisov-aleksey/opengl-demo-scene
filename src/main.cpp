#include <cstdlib>

#include <iostream>
#include <SDL.h>

#include <GL/glew.h>
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/gl.h>
#endif // __APPLE__

#include "application/Application.h"
#include "utils/COutLog.h"

const int width = 640;
const int height = 480;

#ifdef _WIN32
#undef main
#endif //_WIN32

int main(int argc, const char **argv)
{
    SDL_Window *window = NULL;
    Application *app = NULL;
    COutLog *log = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to init SDL : " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

    window = SDL_CreateWindow("Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(window);


    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "failed to initialize GLEW" << std::endl;
        return -1;
    }
    glViewport(0, 0, width, height);

    log = new COutLog();
    app = new Application(window, log);
    app->run();
    delete app;

    SDL_GL_DeleteContext(glcontext);

    if (window) {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}


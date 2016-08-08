#include <ctime>
#include <SDL.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif // __APPLE__

#include "Application.h"

Application::Application(SDL_Window* w) {
    Application(w, new BaseLog());
}


Application::Application(SDL_Window* w, BaseLog* l) {
    window = w;
    frameStart = std::chrono::system_clock::now();
    frameEnd = std::chrono::system_clock::now();

    log = l;
}


Application::~Application() {
    scene = NULL;
    window = NULL;
    log = NULL;
}


void Application::setScene(BaseScene *s) {
    scene = s;
}

/**
 * Main application process cycle is here. Calculates frames delay so we can use
 * real time for tick processing.
 */
void Application::run() {
    running = true;

    while (running) {
        frameLength = frameEnd - frameStart;
        dt = frameLength.count();

        frameStart = std::chrono::system_clock::now();
        processEvents();
        processTick();
        processRender();
        frameEnd = std::chrono::system_clock::now();
    }
}

void Application::processRender() {
    scene->render();
    log->render();
    glFlush();
    SDL_GL_SwapWindow(window);
}


void Application::processEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch(event.type){
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;

                }
                break;
        }
    }
}


void Application::processTick() {
    scene->tick(dt);
    log->add(LOG_DEFAULT, "FPS: %4.4f", 1.0f / dt);
    log->add(LOG_TIMER, "Seconds per frame: %4.6f", dt);
}

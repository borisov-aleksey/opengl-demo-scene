//
// Created by ebolgov on 30.06.16.
//

#ifndef DEMO_SCENE_APPLICATION_H
#define DEMO_SCENE_APPLICATION_H

#include <ctime>
#include "../utils/BaseLog.h"
#include "Object.h"
#include "Shader.h"

#include <SDL.h>

class Application {
    SDL_Window* window;
    BaseLog* log;
    bool running;
    double dt;
    std::clock_t frameStart;
    std::clock_t frameEnd;

    Object *triangle;

    float xrf, yrf, zrf;
public:
    Application(SDL_Window*);
    Application(SDL_Window*, BaseLog*);
    void run();
    void processEvents();
    void processTick();
    void processRender();
    Shader *default_shader;
};


void cube_draw(float xrf, float yrf, float zrf);

#endif //DEMO_SCENE_APPLICATION_H

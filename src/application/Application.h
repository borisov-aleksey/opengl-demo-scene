//
// Created by ebolgov on 30.06.16.
//

#ifndef DEMO_SCENE_APPLICATION_H
#define DEMO_SCENE_APPLICATION_H

#include <ctime>

class Application {
    SDL_Window* window;
    bool running;
    double dt;
    std::clock_t frameStart;
    std::clock_t frameEnd;

    float xrf, yrf, zrf;
public:
    Application(SDL_Window*);
    void run();
    void processEvents();
    void processTick();
    void processRender();
};


void cube_draw(float xrf, float yrf, float zrf);

#endif //DEMO_SCENE_APPLICATION_H

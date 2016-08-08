//
// Created by ebolgov on 30.06.16.
//

#ifndef DEMO_SCENE_APPLICATION_H
#define DEMO_SCENE_APPLICATION_H

#include <chrono>
#include "../utils/BaseLog.h"

typedef std::chrono::time_point<std::chrono::system_clock> application_timepoint;
typedef std::chrono::duration<double> application_frame_length;

class Application {
    SDL_Window* window;
    BaseLog* log;
    bool running;
    double dt;
    application_timepoint frameStart;
    application_timepoint frameEnd;
    application_frame_length frameLength;

    float xrf, yrf, zrf;
public:
    Application(SDL_Window*);
    Application(SDL_Window*, BaseLog*);
    void run();
    void processEvents();
    void processTick();
    void processRender();
};


void cube_draw(float xrf, float yrf, float zrf);

#endif //DEMO_SCENE_APPLICATION_H

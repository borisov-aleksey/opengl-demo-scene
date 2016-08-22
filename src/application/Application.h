//
// Created by ebolgov on 30.06.16.
//

#ifndef DEMO_SCENE_APPLICATION_H
#define DEMO_SCENE_APPLICATION_H

#include <chrono>
#include "../utils/BaseLog.h"
#include "Object.h"
#include "Shader.h"
#include "Character.h"

#include <SDL.h>

#include "../structures/BaseScene.h"

typedef std::chrono::time_point<std::chrono::system_clock> application_timepoint;
typedef std::chrono::duration<double> application_frame_length;

class Application {
    SDL_Window* window;
    BaseLog* log;
    BaseScene* scene;
    bool running;
    double dt;
    application_timepoint frameStart;
    application_timepoint frameEnd;
    application_frame_length frameLength;

    Object *triangle;

    float xrf, yrf, zrf;

public:
    Application(SDL_Window*);
    Application(SDL_Window*, BaseLog*);
    ~Application();
    void run();
    void processEvents();
    void processTick();
    void processRender();

    Shader *default_shader;
    Shader *glyph_shader;
    Character *ch;

    void setScene(BaseScene*);
};

#endif //DEMO_SCENE_APPLICATION_H

//
// Created by ebolgov on 30.06.16.
//

#ifndef DEMO_SCENE_APPLICATION_H
#define DEMO_SCENE_APPLICATION_H

#include <ctime>
#include <SDL_TTF.h>

class Application {
    SDL_Window* window;
    SDL_Renderer * render;
    TTF_Font * font;

    bool running;
    double dt;
    std::clock_t frameStart;
    std::clock_t frameEnd;

    float xrf, yrf, zrf;
public:
    Application(SDL_Window*);
    void renderFont();
    void run();
    void processEvents();
    void processTick();
    void processRender();

private:
    bool ignoreFont;
};


void cube_draw(float xrf, float yrf, float zrf);

#endif //DEMO_SCENE_APPLICATION_H

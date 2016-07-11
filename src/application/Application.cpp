//
// Created by ebolgov on 30.06.16.
//

#include <ctime>
#include <SDL.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif // __APPLE__

#include "Application.h"

Application::Application(SDL_Window* w) {
    window = w;
    frameStart = std::clock();
    frameEnd = std::clock();

    xrf = 0.0f;
    yrf = 0.0f;
    zrf = 0.0f;
}

/**
 * Main application process cycle is here. Calculates frames delay so we can use
 * real time for tick processing.
 */
void Application::run() {
    running = true;
    TTF_Init();
    render = SDL_CreateRenderer(window,-1,0);

#ifdef _WIN32
        font = TTF_OpenFont("..\\resources\\fonts\\font.ttf", 25);
#else
        font = TTF_OpenFont("../resources/fonts/font.ttf", 25);
#endif

    if (font == NULL)
        ignoreFont = true;
    while (running) {
        dt = 1000.0 * (frameEnd - frameStart) / CLOCKS_PER_SEC;

        frameStart = std::clock();
        processEvents();
        processTick();
        processRender();

        SDL_GL_SwapWindow(window);
        frameEnd = std::clock();
    }
    TTF_CloseFont(font);
    TTF_Quit();
}

void Application::renderFont(){

    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(font, "Bloody Text", color);
    // surface = TTF_RenderUNICODE_Solid(font, text, color); 
    SDL_Texture * texture = SDL_CreateTextureFromSurface(render, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect position = { 0, 0, texW, texH };
    
    SDL_RenderCopy(render, texture,  NULL, &position);

    SDL_RenderPresent(render);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Application::processRender() {
    cube_draw(xrf, yrf, zrf);
    if(!ignoreFont)
        renderFont();
    glFlush();
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
    if (xrf < 90) {
        xrf += 1 * dt;
    } else {
        if (yrf < 90) {
            yrf += 1 * dt;
        } else {
            if (zrf < 90) {
                zrf += 1 * dt;
            } else {
                xrf = 0.0f;
                yrf = 0.0f;
                zrf = 0.0f;
            }
        }
    }
    //yrf -= 0.5;
    //zrf -= 0.5;
}


void cube_draw(float xrf, float yrf, float zrf)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -7.0f);

    glRotatef(xrf, 1.0f, 0.0f, 0.0f);
    glRotatef(yrf, 0.0f, 1.0f, 0.0f);
    glRotatef(zrf, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glEnd();
}

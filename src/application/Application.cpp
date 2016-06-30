//
// Created by ebolgov on 30.06.16.
//

#include <ctime>
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

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
    while (running) {
        dt = 1000.0 * (frameEnd - frameStart) / CLOCKS_PER_SEC;

        frameStart = std::clock();
        processEvents();
        processTick();
        processRender();

        SDL_GL_SwapWindow(window);
        frameEnd = std::clock();
    }
}

void Application::processRender() {
    cube_draw(xrf, yrf, zrf);

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

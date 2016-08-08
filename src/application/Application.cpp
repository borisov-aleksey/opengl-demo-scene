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
    frameStart = std::chrono::system_clock::now();
    frameEnd = std::chrono::system_clock::now();

    xrf = 0.0f;
    yrf = 0.0f;
    zrf = 0.0f;

    log = new BaseLog();
}


Application::Application(SDL_Window* w, BaseLog* l) {
    window = w;
    frameStart = std::chrono::system_clock::now();
    frameEnd = std::chrono::system_clock::now();

    xrf = 0.0f;
    yrf = 0.0f;
    zrf = 0.0f;
    log = l;
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

        SDL_GL_SwapWindow(window);
        frameEnd = std::chrono::system_clock::now();
    }
}

void Application::processRender() {
    cube_draw(xrf, yrf, zrf);
    log->render();
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
    float speed = 90;
    if (xrf < 90) {
        xrf += speed * dt;
    } else {
        if (yrf < 90) {
            yrf += speed * dt;
        } else {
            if (zrf < 90) {
                zrf += speed * dt;
            } else {
                xrf = 0.0f;
                yrf = 0.0f;
                zrf = 0.0f;
            }
        }
    }

    log->add(LOG_DEFAULT, "FPS: %4.4f", 1.0f / dt);
    log->add(LOG_TIMER, "Seconds per frame: %4.6f", dt);
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

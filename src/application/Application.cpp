#include "Application.h"

#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <iostream>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif // __APPLE__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
Application::Application(SDL_Window* w) {
    window = w;
    frameStart = std::clock();
    frameEnd = std::clock();

    xrf = 0.0f;
    yrf = 0.0f;
    zrf = 0.0f;

    log = new BaseLog();
}
*/


Application::Application(SDL_Window* w, BaseLog* l) {
    window = w;
    frameStart = std::clock();
    frameEnd = std::clock();

    triangle = new Object();
    default_shader = new Shader("shaders/default.vert", "shaders/default.frag");
    glyph_shader = new Shader("shaders/glyphs.vert", "shaders/glyphs.frag");

    ch = new Character('A');

    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(640), 0.0f, static_cast<GLfloat>(480));
    glyph_shader->Use();
    glUniformMatrix4fv(glGetUniformLocation(glyph_shader->Program, "projection"), 1, GL_FALSE,
                       glm::value_ptr(projection));

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
        dt = ((float)frameEnd - (float)frameStart) / CLOCKS_PER_SEC;

        frameStart = std::clock();
        processEvents();
        processTick();
        processRender();

        frameEnd = std::clock();
    }
}

void Application::processRender() {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //default_shader->Use();
    //glBindVertexArray(triangle->VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    //glBindVertexArray(0);

    ch->Render(glyph_shader, 25.0f, 23.0f, 1.0f, glm::vec3(0.5f, 0.8f, 0.2f));
    //log->render();
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

    //log->add(LOG_FPS, 1.0f / dt);
    //log->add(LOG_TIMER, dt);
}


void cube_draw(float xrf, float yrf, float zrf)
{

}

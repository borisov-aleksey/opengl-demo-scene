//
// Created by  Nikita Rodionov on 24.07.16.
//

#ifndef DEMO_SCENE_OBJECT_H
#define DEMO_SCENE_OBJECT_H

#include <cstdlib>

#include <OpenGL/OpenGL.h>

class Object {
private:
    GLfloat *vertices;
    size_t vertices_count;

public:
    Object();
    ~Object();

    GLuint VBO;
    GLuint VAO;
};


#endif //DEMO_SCENE_OBJECT_H

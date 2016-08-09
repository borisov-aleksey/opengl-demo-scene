//
// Created by  Nikita Rodionov on 24.07.16.
//

#ifndef DEMO_SCENE_OBJECT_H
#define DEMO_SCENE_OBJECT_H

#include <cstdlib>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif //__APPLE__

class Object {
private:
    GLfloat *vertices;

    size_t  vertices_count;
    size_t  vertex_size;

public:
    Object();
    ~Object();

    GLuint VBO;
    GLuint VAO;
};


#endif //DEMO_SCENE_OBJECT_H

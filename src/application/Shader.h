
#ifndef DEMO_SCENE_SHADER_H
#define DEMO_SCENE_SHADER_H

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#else
#include "GL/glew.h"
#include <GL/gl.h>
#endif //__APPLE__

class Shader {
public:
    GLuint Program;
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
    void Use();
};

#endif //DEMO_SCENE_SHADER_H


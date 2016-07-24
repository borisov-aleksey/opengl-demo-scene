
#ifndef DEMO_SCENE_SHADER_H
#define DEMO_SCENE_SHADER_H

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

class Shader {
public:
    GLuint Program;
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
    void Use();
};

#endif //DEMO_SCENE_SHADER_H


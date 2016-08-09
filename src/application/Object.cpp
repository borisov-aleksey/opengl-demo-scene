#ifdef __APPLE__
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#include <GL/gl.h>
#endif //__APPLE__
#include "Object.h"

Object::Object()
{


    vertices = new GLfloat[9];

    vertices[0] = -0.9f; vertices[1] = -0.5f; vertices[2] = 0.0f;
    vertices[3] = -0.0f; vertices[4] = -0.5f; vertices[5] = 0.0f;
    vertices[6] = -0.45f; vertices[7] = 0.5f; vertices[8] = 0.0f;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

Object::~Object()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
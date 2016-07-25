#ifndef DEMO_SCENE_CHARACTER_H
#define DEMO_SCENE_CHARACTER_H

#include "Shader.h"

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <OpenGL/OpenGL.h>

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
#include <freetype/freetype.h>

class Character {
public:
    GLuint textureID;
    glm::ivec2 size;    // size of glyph
    glm::ivec2 bearing; // offset from baseline to left/top of glyph
    GLuint advance;     // horizontal offset to advance to next glyph

    GLuint VAO;
    GLuint VBO;

    Character(GLubyte character);
    void Render(Shader *shader, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
};

#endif //DEMO_SCENE_CHARACTER_H


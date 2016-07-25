#include <iostream>
#include <GL/glew.h>
#include "Character.h"

Character::Character(GLubyte character)
{
    FT_Library ft;

    if (FT_Init_FreeType(&ft))
        std::cout << "error::freetype: could not init FreeType Library" << std::endl;

    FT_Face face;
    if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
        std::cout << "error::freetype: failed to load font" << std::endl;

    FT_Set_Pixel_Sizes(face, 0, 48);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if (FT_Load_Char(face, character, FT_LOAD_RENDER))
        std::cout << "error::freetype:: failed to load glyph" << std::endl;

    GLuint texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED,
                 face->glyph->bitmap.width, face->glyph->bitmap.rows,
                 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    textureID = texture;
    size = glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
    bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
    advance = face->glyph->advance.x;

    glBindTexture(GL_TEXTURE_2D, 0);

    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Character::Render(Shader *shader, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
{
    shader->Use();

    glUniform3f(glGetUniformLocation(shader->Program, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(VAO);

    GLfloat xpos = x + bearing.x * scale;
    GLfloat ypos = y - (size.y - bearing.y) * scale;

    GLfloat w = size.x + scale;
    GLfloat h = size.y * scale;

    GLfloat vertices[6][4] = {
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos,     ypos,       0.0, 1.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos + w, ypos + h,   1.0, 0.0 }
    };

    glBindTexture(GL_TEXTURE_2D, textureID);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

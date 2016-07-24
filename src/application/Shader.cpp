#include "Shader.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath)
{
    // retrieve the vertex/fragment source code
    std::string vertexSource;
    std::string fragmentSource;

    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    vertexShaderFile.exceptions(std::ifstream::badbit);
    fragmentShaderFile.exceptions(std::ifstream::badbit);

    try {
        vertexShaderFile.open(vertexPath);
        fragmentShaderFile.open(fragmentPath);

        std::stringstream vertexShaderStream;
        std::stringstream fragmentShaderStream;

        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexSource = vertexShaderStream.str();
        fragmentSource = fragmentShaderStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "error::shader::file_not_successfully_read" << std::endl;
    }

    const GLchar *vertexShaderCode = vertexSource.c_str();
    const GLchar *fragmentShaderCode = fragmentSource.c_str();

    // compile shaders
    GLuint vertex;
    GLuint fragment;
    GLint success;
    GLchar infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShaderCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "error:shader::vertex::compilation_failed\n" << infoLog << std::endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShaderCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "error:shader::fragment::compilation_failed\n" << infoLog << std::endl;
    }

    this->Program = glCreateProgram();
    glAttachShader(this->Program, vertex);
    glAttachShader(this->Program, fragment);
    glLinkProgram(this->Program);

    glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
        std::cout << "error:shader::program::linking_failed\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Use()
{
    glUseProgram(this->Program);
}


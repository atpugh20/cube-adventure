#pragma once

#pragma once

#include "glad/glad.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Macros.h"

class Shader {
private:
    unsigned int id;

    // Debug attributes
    int success;
    char infoLog[512];

public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void Use() const;

    std::string ParseShader(const char *filePath);

    void CompileShader(unsigned int &shaderID, const std::string &source);

    // Debug Methods

    void LinkProgram(const unsigned int &vs, const unsigned int &fs);

    unsigned int GetID() const;

    unsigned int GetUniformLocation(const std::string &name) const;

    void SetInt(const std::string &name, int value) const;
    void SetFloat(const std::string &name, float value) const;

    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const;
};

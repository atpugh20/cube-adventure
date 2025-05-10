#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    id = glCreateProgram();

    CompileShader(vs, ParseShader(vertexPath));
    CompileShader(fs, ParseShader(fragmentPath));
    LinkProgram(vs, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::Use() const {
    glUseProgram(id);
}

std::string Shader::ParseShader(const char *filePath) {
    /*
    * Converts a the shader located at 'shaderPath' to
    * a string, then returns it
    */
    std::ifstream stream(filePath);
    std::string line;
    std::stringstream ss;

    while (getline(stream, line)) {
        ss << line << '\n';
    }

    return ss.str();
}

void Shader::CompileShader(unsigned int &shaderID, const std::string &source) {
    const char *src = source.c_str();
    glShaderSource(shaderID, 1, &src, nullptr);
    glCompileShader(shaderID);

    // Error handling
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        print("Shader compilation failed");
        print(infoLog);
    }
}

// Debug Methods

void Shader::LinkProgram(const unsigned int &vs, const unsigned int &fs) {
    glAttachShader(id, vs);
    glAttachShader(id, fs);
    glLinkProgram(id);

    // Error handling
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        print("Program link failed");
        print(infoLog);
    }
}

unsigned int Shader::GetID() const { return id; }

unsigned int Shader::GetUniformLocation(const std::string &name) const {
    unsigned int location = glGetUniformLocation(id, name.c_str());
    if (location == -1)
        print("Warning: uniform '" + name + "' doesn't exist.");
    return location;
}

void Shader::SetInt(const std::string &name, int value) const {
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(const std::string &name, float value) const {
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) const {
    glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}


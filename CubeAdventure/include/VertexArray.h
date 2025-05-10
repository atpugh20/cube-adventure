#pragma once

#include "glad/glad.h"

class VertexArray {
private:
    unsigned int id;

public:
    VertexArray();
    ~VertexArray();

    void Bind() const;

    void Unbind() const;
};
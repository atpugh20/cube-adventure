#pragma once

#include <cstdlib>

#include "glad/glad.h"
#include "Vertex.h"

class VertexBuffer {
private:
    unsigned int id;

public:
    VertexBuffer();
    ~VertexBuffer();

    void Bind(const void *data, const unsigned int &size) const;

    void Rebind(const void *data, const unsigned int &size) const;

    void Unbind() const;

    void SetAttributes() const;
};
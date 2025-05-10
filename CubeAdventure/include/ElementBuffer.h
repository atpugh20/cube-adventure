#pragma once

#include "glad/glad.h"

class ElementBuffer {
private:
    unsigned int id;

public:
    ElementBuffer();
    ~ElementBuffer();

    void Bind(const void *data, unsigned int size) const;

    void Unbind() const;
};
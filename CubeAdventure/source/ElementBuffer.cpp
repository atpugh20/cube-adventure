#include "ElementBuffer.h"    

ElementBuffer::ElementBuffer() {
    glGenBuffers(1, &id);
}
ElementBuffer::~ElementBuffer() {
    glDeleteBuffers(1, &id);
}

void ElementBuffer::Bind(const void *data, unsigned int size) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void ElementBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
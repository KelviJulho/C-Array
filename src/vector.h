#include "stdlib.h"
#include "stdio.h"

#ifndef VECTOR_H
#define VECTOR_H

#define MAKE_VECTOR(T)\
typedef struct {\
    T * data;\
    unsigned int length;\
    unsigned int capacity;\
} Vector_##T;\
Vector_##T * new_vector_##T(unsigned int capacity) {\
    Vector_##T * vector = (Vector_##T*)malloc(sizeof(Vector_##T));\
\
    vector->data = (T*)malloc(sizeof(T) * capacity);\
    vector->length = 0;\
    vector->capacity = capacity;\
\
    return vector;\
}\
void vector_push_##T(Vector_##T * self, T value) {\
    if (self->length >= self->capacity) {\
        unsigned int new_capacity = self->capacity * 2;\
        \
        T * data = (T*)realloc(self->data, sizeof(T) * new_capacity);\
        if (data == NULL) {\
            perror("error resizing vector");\
            abort();\
        }\
        \
        self->data = data;\
        self->capacity = new_capacity;\
    }\
\
    ((T*)self->data)[self->length] = value;\
    self->length += 1;\
}\
T vector_pop_##T(Vector_##T * self) {\
    if(self->length == 0) {\
        perror("attamp pop empty vector");\
        abort();\
    }\
    self->length -= 1;\
    return ((T*)self->data)[self->length];\
}\
T vector_get_##T(Vector_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get vector index out of limits");\
        abort();\
    }\
    return ((T*)self->data)[index];\
}\
T * vector_get_mut_##T(Vector_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get vector index out of limits");\
        abort();\
    }\
    return &((T*)self->data)[index];\
}\
void vector_set_##T(Vector_##T * self, unsigned int index, T value) {\
    if(index >= self->length) {\
        perror("attampt set vector index out of limits");\
        abort();\
    }\
    ((T*)self->data)[index] = value;\
}\

#endif
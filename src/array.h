#include "stdlib.h"
#include "stdio.h"

#ifndef ARRAY_H
#define ARRAY_H

//T is type of array
#define MAKE_ARRAY(T)\
typedef struct{\
    T * data;\
    unsigned int length;\
    unsigned int capacity;\
} Array_##T;\
Array_##T * new_array_##T(unsigned int capacity) {\
    Array_##T * array = (Array_##T*)malloc(sizeof(Array_##T));\
\
    array->data = (T*)malloc(sizeof(T) * capacity);;\
    array->length = 0;\
    array->capacity = capacity;\
\
    return array;\
}\
void array_append_##T(Array_##T * self, T value) {\
    ((T*)self->data)[self->length] = value;\
    self->length += 1;\
}\
T array_pop_##T(Array_##T * self) {\
    if(self->length == 0) {\
        perror("attamp pop empty array");\
        abort();\
    }\
    self->length -= 1;\
    return ((T*)self->data)[self->length];\
}\
T array_disordered_remove_##T(Array_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt remove index out of limits");\
        abort();\
    }\
\
    T value;\
    if (index == self->length - 1) {\
        value = ((T*)self->data)[index];\
    } else {\
        value = ((T*)self->data)[index];\
        ((T*)self->data)[index] = ((T*)self->data)[self->length-1];\
    }\
    self->length -= 1;\
    return value;\
}\
T array_ordered_remove_##T(Array_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt remove index out of limits");\
        abort();\
    }\
\
    T value;\
    if (index == self->length - 1) {\
        value = ((T*)self->data)[index];\
    } else {\
        value = ((T*)self->data)[index];\
        for (size_t i = 0; i < self->length - index; i++){\
           ((T*)self->data)[index + i] = ((T*)self->data)[index + 1 + i];\
        }\
    }\
    self->length -= 1;\
    return value;\
}\
T array_get_##T(Array_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get array index out of limits");\
        abort();\
    }\
    return ((T*)self->data)[index];\
}\
T * array_get_mut_##T(Array_##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get array index out of limits");\
        abort();\
    }\
    return &((T*)self->data)[index];\
}\
void array_set_##T(Array_##T * self, unsigned int index, T value) {\
    if(index >= self->length) {\
        perror("attampt set array index out of limits");\
        abort();\
    }\
    ((T*)self->data)[index] = value;\
}\
typedef struct{\
    unsigned int index;\
    Array_##T * array;\
} Array_Iterator_##T;\
Array_Iterator_##T * array_iterator_##T(Array_##T * self) {\
    Array_Iterator_##T * iter = (Array_Iterator_##T*)malloc(sizeof(Array_Iterator_##T));\
\
    iter->index = 0;\
    iter->array = self;\
\
    return iter;\
}\
T * array_iterator_next_##T(Array_Iterator_##T * self) {\
    if (self->index >= self->array->length) {\
        return NULL;\
    }\
\
    T * value = &((T*)self->array->data)[self->index];\
    self->index += 1;\
    return value;\
}\

#endif
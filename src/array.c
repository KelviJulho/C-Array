#include "stdlib.h"
#include "stdio.h"

//T is type of array
#define MAKE_ARRAY(T)\
typedef struct{\
    T * data;\
    unsigned int length;\
    unsigned int capacity;\
} Array##T;\
Array##T * new_array_##T(unsigned int capacity) {\
    Array##T * array = (Array##T*)malloc(sizeof(Array##T));\
\
    T * data = (T*)malloc(sizeof(T) * capacity);\
\
    array->data = data;\
    array->length = 0;\
    array->capacity = capacity;\
\
    return array;\
}\
void array_append_##T(Array##T * self, T value) {\
    ((T*)self->data)[self->length] = value;\
    self->length += 1;\
}\
T array_disordered_remove_##T(Array##T * self, unsigned int index) {\
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
T array_ordered_remove_##T(Array##T * self, unsigned int index) {\
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
T array_get_##T(Array##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get index out of limits");\
        abort();\
    }\
    return ((T*)self->data)[index];\
}\
T * array_get_mut_##T(Array##T * self, unsigned int index) {\
    if(index >= self->length) {\
        perror("attampt get index out of limits");\
        abort();\
    }\
    return &((T*)self->data)[index];\
}\
void array_set_##T(Array##T * self, unsigned int index, T value) {\
    if(index >= self->length) {\
        perror("attampt set index out of limits");\
        abort();\
    }\
    ((T*)self->data)[index] = value;\
}
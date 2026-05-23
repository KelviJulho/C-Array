#include "stdio.h"

#include "src/array.h"
#include "src/vector.h"

MAKE_VECTOR(int)
MAKE_ARRAY(int)

int main(int argc, char const *argv[]) {
    Vector_int * v = new_vector_int(10);

    for (size_t i = 0; i < 50; i++)
    {
        vector_push_int(v, i);
    }

    Array_int * a = new_array_int(v->capacity);

    while (v->length > 0){
        array_append_int(a, vector_pop_int(v));
    }

    Array_Iterator_int * i = array_iterator_int(a);

    int * value;
    while ((value = array_iterator_next_int(i)) != NULL) {
        printf("%u\n", *value);
    }
    
    return 0;
}

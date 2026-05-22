#include "stdio.h"

#include "src/array.c"

MAKE_ARRAY(int);

typedef struct {
    int x;
    int y;
} Vector2;

MAKE_ARRAY(Vector2);

int main(int argc, char const *argv[]) {
    Arrayint * a = new_array_int(10);

    for (size_t i = 0; i < 10; i++)
    {
        array_append_int(a, i);
    }

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", array_get_int(a, i));
    }

    printf("\n");

    array_ordered_remove_int(a, 5);
    
    for (size_t i = 0; i < a->length; i++)
    {
        printf("%d ", array_get_int(a, i));
    }

    printf("\n");


    ArrayVector2 * av = new_array_Vector2(10);

    for (size_t i = 0; i < 10; i++)
    {
        Vector2 v = {i, i};
        array_append_Vector2(av, v);
    }

    for (size_t i = 0; i < av->length; i++)
    {   
        Vector2 v = array_get_Vector2(av, i);
        printf("Vector{%d, %d}", v.x, v.y);
    }

    printf("\n");

    array_ordered_remove_Vector2(av, 2);

    for (size_t i = 0; i < av->length; i++)
    {   
        Vector2 v = array_get_Vector2(av, i);
        printf("Vector{%d, %d}", v.x, v.y);
    }

    printf("\n");

    Vector2 * v_ptr = array_get_mut_Vector2(av, 6);
    v_ptr->x = 100;


    Vector2 v = {-10, -999};
    array_set_Vector2(av, 1, v);

    for (size_t i = 0; i < av->length; i++)
    {   
        Vector2 v = array_get_Vector2(av, i);
        printf("Vector{%d, %d}", v.x, v.y);
    }

    printf("\n");

    return 0;
}

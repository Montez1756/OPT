#include "utils.h"


void add_to_array(void **arr, size_t *size, size_t elem_size, void *target)
{
    void **new_arr = realloc(*arr, elem_size * ((*size) + 1));
    if(new_arr == NULL)
    {
        perror("realloc");
        return;
    }

    new_arr[*size] = target;
    (*size)++;
    *arr = new_arr;
}

int array_includes(void **arr, const size_t *size, void *target, int (*cmp)(void *, void *))
{
    for(size_t i=0; i<*size; i++)
    {
        if(cmp(arr[i], target))
        {
            return 1;
        }
    }
    return 0;
}
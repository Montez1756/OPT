#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

void add_to_array(void **arr, size_t *size, size_t elem_size, void *target);
int array_includes(void **arr, const size_t *size, void *target, int(*cmp)(void *, void *));
void add_to_string();

#endif
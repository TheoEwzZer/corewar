/*
** EPITECH PROJECT, 2023
** my_calloc
** File description:
** my_calloc
*/

#include "my.h"

void *my_memset(void *s, int c, size_t n)
{
    char *ptr = s;

    if (!s)
        return NULL;
    for (size_t i = 0; i < n; i++)
        ptr[i] = c;
    return s;
}

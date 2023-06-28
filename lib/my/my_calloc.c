/*
** EPITECH PROJECT, 2023
** my_calloc
** File description:
** my_calloc
*/

#include "my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);
    char *p = NULL;

    if (ptr) {
        p = ptr;
        for (size_t i = 0; i < nmemb * size; i++)
            p[i] = 0;
    }
    return ptr;
}

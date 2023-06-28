/*
** EPITECH PROJECT, 2023
** my_strchr
** File description:
** my_strchr
*/

#include "my.h"

char *my_strchr(const char *s, int c)
{
    for (size_t i = 0; s[i]; i++) {
        if (s[i] == c)
            return (char *)&s[i];
    }
    return NULL;
}

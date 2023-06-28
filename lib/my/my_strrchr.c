/*
** EPITECH PROJECT, 2023
** my_strrchr
** File description:
** my_strrchr
*/

#include "my.h"
#include <string.h>

char *my_strrchr(const char *s, int c)
{
    const size_t len = my_strlen(s);

    for (size_t i = len; i > 0; i--) {
        if (s[i - 1] == c)
            return (char *)&s[i - 1];
    }
    return NULL;
}

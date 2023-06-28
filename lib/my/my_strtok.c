/*
** EPITECH PROJECT, 2023
** my_strtok
** File description:
** my_strtok
*/

#include "my.h"

char *my_strtok(char *str, const char *delim)
{
    static char *saved_token = NULL;
    char *token = NULL;
    if (!str && !saved_token)
        return NULL;
    if (str)
        saved_token = str;
    token = saved_token;
    for (; *saved_token && my_strchr(delim, *saved_token); saved_token++);
    if (!(*saved_token)) {
        saved_token = NULL;
        return NULL;
    }
    token = saved_token;
    for (; *saved_token && !my_strchr(delim, *saved_token); saved_token++);
    if (*saved_token) {
        *saved_token = '\0';
        saved_token++;
    } else
        saved_token = NULL;
    return token;
}

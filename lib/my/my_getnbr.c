/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** Returns a number, sent to the function as a string.
*/

#include "my.h"

int isdigit(int c)
{
    return c >= '0' && c <= '9';
}

int my_getnbr(const char *str)
{
    int result = 0, sign = 1;
    size_t i = 0;

    if (!str || !str[0])
        return 0;
    while (str[0] && !isdigit(str[0]) && str[0] != '+' && str[0] != '-')
        str++;
    if (str[0] == '-') {
        sign = -1;
        i++;
    } else if (str[0] == '+') {
        i++;
    }
    while (isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}

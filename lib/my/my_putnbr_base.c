/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** Converts and displays a decimal number into a number in a given base.
** The number is given as an int and the base is provided as a string.
** The base contains all the symbols that can be used to print a number
** (for instance, 0123456789 for the decimal base, 01 for the binary base,
** 0123456789ABCDEF for the hexadecimal base).
** The function must deal with negative numbers
*/

#include "my.h"
#include <unistd.h>

void my_putnbr_base(unsigned int nbr, const char *base)
{
    int len = my_strlen(base);
    char output[9] = "00000000";
    int i = 7;

    while (nbr > 0 && i >= 0) {
        output[i] = base[nbr % len];
        nbr /= len;
        i--;
    }
    write(1, "\033[1;30m", 7);
    for (i = 0; i < 8; i++) {
        my_putchar(output[i]);
    }
    write(1, "\033[0m", 4);
}

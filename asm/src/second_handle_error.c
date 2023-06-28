/*
** EPITECH PROJECT, 2023
** second handle error
** File description:
** Gappy
*/

#include "asm.h"

bool exist(char *function)
{
    for (size_t i = 0; op_tab[i].nbr_args; i++) {
        if (!my_strcmp(function, op_tab[i].mnemonique))
            return true;
    }
    return false;
}

void compare_with_tab(int bytes, size_t i, int rank)
{
    if (i > 4)
        exit(84);
    if (i == T_REG)
        if (bytes > op_tab[rank].type[0])
            exit(84);
    if (i == T_DIR)
        if (bytes > op_tab[rank].type[1])
            exit(84);
}

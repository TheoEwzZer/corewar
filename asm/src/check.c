/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

void check_op_extreme(char *function)
{
    for (size_t i = 0; function[i]; i++) {
        if (function[i] == ':' && function[i + 1] == ':')
            exit(84);
    }
}

void check_register(int register_int)
{
    if (register_int < 1 || register_int > REG_NUMBER)
        exit(84);
}

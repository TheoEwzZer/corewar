/*
** EPITECH PROJECT, 2023
** handle error
** File description:
** Gappy
*/

#include "asm.h"

void check_type(asm_t *my_asm, size_t i, asm_t *pos, int rank)
{
    int bytes = 0;

    if (op_tab[rank].nbr_args == 16)
        exit(84);
    if (my_asm->finaltab[pos->i][i][0] == REGISTER_CHAR)
        bytes = 1;
    if (my_asm->finaltab[pos->i][i][0] == DIRECT_CHAR) {
        if (my_strlen(my_asm->finaltab[pos->i][i]) <= 1)
            exit(84);
        if (my_asm->finaltab[pos->i][i][1] == LABEL_CHAR)
            return;
        if (my_asm->finaltab[pos->i][i][1] != LABEL_CHAR)
            bytes = 2;
    }
    if (!bytes)
        bytes = 4;
    compare_with_tab(bytes, i, rank);
}

void check_args(asm_t *my_asm, asm_t *pos)
{
    int rank = 0;
    char *register_tmp = NULL;
    int register_int = 1;
    char x = (char)(my_strlen_double(my_asm->finaltab[pos->i]) - 1);
    for (size_t i = 0; my_asm->finaltab[pos->i][i]; i++) {
        if (my_asm->finaltab[pos->i][i][0] == REGISTER_CHAR) {
            register_tmp = my_strdup(my_asm->finaltab[pos->i][i]);
            register_tmp++;
            register_int = my_getnbr(register_tmp);
            check_register(register_int);
        }
    }
    while (op_tab[rank].nbr_args &&
        my_strcmp(op_tab[rank].mnemonique, my_asm->finaltab[pos->i][0]))
        rank++;
    if (x != op_tab[rank].nbr_args || x < 0 || x >= MAX_ARGS_NUMBER)
        exit(84);
    for (size_t i = 0; my_asm->finaltab[pos->i][i]; i++)
        check_type(my_asm, i, pos, rank);
}

void check_function(asm_t *my_asm, asm_t *pos)
{
    char *function = my_asm->finaltab[pos->i][0];
    char *function2 = my_asm->finaltab[pos->i][1];

    if (exist(function)) {
        check_args(my_asm, pos);
        return;
    }
    check_op_extreme(function);
    if (function[my_strlen(function) - 1] == LABEL_CHAR) {
        check_args2(my_asm, pos);
        check_label_name(function);
        return;
    }
    if (function2[my_strlen(function2) - 1] == LABEL_CHAR)
        exit(84);
}

void verify_tab2(asm_t *my_asm, asm_t *pos)
{
    size_t cpt = 0;

    for (size_t k = 0; my_asm->finaltab[pos->i][k]; k++) {
        cpt++;
    }
    if (cpt == 1) {
        if (my_asm->finaltab[pos->i][0]
        [my_strlen(my_asm->finaltab[pos->i][0]) - 1] != LABEL_CHAR)
            exit(84);
    }
    check_function(my_asm, pos);
}

void verify_tab(asm_t *pos)
{
    for (pos->i = 0; pos->finaltab[pos->i]; pos->i++) {
        for (pos->j = 0; pos->finaltab[pos->i][pos->j]; pos->j++) {
            verify_tab2(pos, pos);
        }
    }
}

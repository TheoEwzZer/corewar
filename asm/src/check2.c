/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

char **my_strdup_double(char **str)
{
    size_t len = my_strlen_double(str);
    char **str2 = my_calloc(len + 1, sizeof(char *));

    for (size_t i = 0; str[i]; i++)
        str2[i] = my_strdup(str[i]);
    return str2;
}

void check_type2(asm_t *my_asm, size_t i, asm_t *pos, int rank)
{
    char **tmp = my_strdup_double(my_asm->finaltab[pos->i]);
    int bytes = 0;

    if (tmp[1])
        tmp++;
    if (op_tab[rank].nbr_args == 16)
        exit(84);
    if (tmp[i][0] == REGISTER_CHAR)
        bytes = 1;
    if (tmp[i][0] == DIRECT_CHAR) {
        if (my_strlen(tmp[i]) <= 1)
            exit(84);
        if (tmp[i][1] == LABEL_CHAR)
            return;
        if (tmp[i][1] != LABEL_CHAR)
            bytes = 2;
    }
    if (!bytes)
        bytes = 4;
    compare_with_tab(bytes, i, rank);
}

void check_args2(asm_t *my_asm, asm_t *pos)
{
    char **tmp = my_strdup_double(my_asm->finaltab[pos->i]);
    int rank = 0;
    char x = '\0';

    if (tmp[1])
        tmp++;
    x = (char)(my_strlen_double(tmp) - 1);
    while (op_tab[rank].nbr_args &&
        my_strcmp(op_tab[rank].mnemonique, tmp[0])) {
        rank++;
    }
    if (x != op_tab[rank].nbr_args || x < 0 || x >= MAX_ARGS_NUMBER)
        exit(84);
    for (size_t i = 0; tmp[i]; i++)
        check_type2(my_asm, i, pos, rank);
}

void check_label_name2(const char *label, size_t i, bool *char_found)
{
    const char *allowed_chars = LABEL_CHARS;

    for (size_t j = 0; allowed_chars[j]; j++) {
        if (label[i] == allowed_chars[j]) {
            *char_found = true;
            break;
        }
    }
}

void check_label_name(const char *label)
{
    bool char_found = false;

    for (size_t i = 0; label[i + 1]; i++) {
        char_found = false;
        check_label_name2(label, i, &char_found);
        if (!char_found)
            exit(84);
    }
}

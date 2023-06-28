/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void check_cli(vm_t *vm, char **argv, size_t *i)
{
    if (!my_strcmp(argv[*i], "-dump")) {
        if (!argv[*i + 1] || !my_isnum(argv[*i + 1]) || argv[*i + 1][0] == '-')
            my_exit(vm, 84);
        (*i)++;
        return;
    }
    if (!my_strcmp(argv[*i], "-n")) {
        if (!argv[*i + 1] || !my_isnum(argv[*i + 1]) || argv[*i + 1][0] == '-')
            my_exit(vm, 84);
        (*i)++;
        return;
    }
    if (!my_strcmp(argv[*i], "-a")) {
        if (!argv[*i + 1] || !my_isnum(argv[*i + 1]) || argv[*i + 1][0] == '-')
            my_exit(vm, 84);
        (*i)++;
        return;
    }
    if (!is_cor_file(argv[*i]))
        exit(84);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void my_exit(vm_t *vm, int status)
{
    for (size_t i = 0; vm->champions[i]; i++) {
        free(vm->champions[i]->header);
        free(vm->champions[i]);
    }
    for (size_t i = 0; vm->processus[i]; i++)
        free(vm->processus[i]);
    free(vm->champions);
    free(vm->processus);
    free(vm->arena);
    free(vm->color_arena);
    free(vm);
    exit(status);
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_aff(vm_t *vm, processus_t *processus)
{
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3, first_arg = 0;
    if (first_type != 1)
        return;
    processus->pc += 2;
    first_arg = get_arg(vm, processus, first_type, 16);
    my_putchar((char)(REG[first_arg - 1] % 256));
    processus->cycle += 2;
}

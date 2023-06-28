/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_add(vm_t *vm, processus_t *processus)
{
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3, first_arg = 0;
    int second_type = (coding_byte >> 4) & 3, second_arg = 0;
    int third_type = (coding_byte >> 2) & 3, third_arg = 0;

    processus->pc += 2; processus->carry = true;
    first_arg = get_arg(vm, processus, first_type, 4);
    second_arg = get_arg(vm, processus, second_type, 4);
    third_arg = get_arg(vm, processus, third_type, 4);
    if (!(first_type == 1 && second_type == 1 && third_type == 1)) {
        processus->carry = false; return;
    }
    REG[third_arg - 1] = REG[first_arg - 1]
    + REG[second_arg - 1];
    processus->cycle += 10;
}

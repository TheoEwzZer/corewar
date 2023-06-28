/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_lld(vm_t *vm, processus_t *processus)
{
    int actual_pc = processus->pc;
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3, first_arg = 0;
    int second_type = (coding_byte >> 4) & 3, second_arg = 0;
    processus->pc += 2; processus->carry = true;
    first_arg = get_arg(vm, processus, first_type, 13);
    second_arg = get_arg(vm, processus, second_type, 13);
    if (second_type != 1) {
        processus->carry = false; return;
    } if (first_type == 1) {
        REG[second_arg - 1] = REG[first_arg - 1];
    } else if (first_type == 2) {
        REG[second_arg - 1] = first_arg;
    } else {
        REG[second_arg - 1] =
        vm->arena[(first_arg + actual_pc) % MEM_SIZE] * 256 * 256 * 256
        + vm->arena[(first_arg + actual_pc + 1) % MEM_SIZE] * 256 * 256
        + vm->arena[(first_arg + actual_pc + 2) % MEM_SIZE] * 256
        + vm->arena[(first_arg + actual_pc + 3) % MEM_SIZE];
    } processus->cycle += 10;
}

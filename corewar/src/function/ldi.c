/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_ldi(vm_t *vm, processus_t *processus)
{
    int actual_pc = processus->pc;
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3, first_arg = 0, first = 0;
    int second_type = (coding_byte >> 4) & 3, second_arg = 0, second = 0;
    int third_type = (coding_byte >> 2) & 3, third_arg = 0;
    int sum = 0;
    processus->pc += 2; processus->carry = true;
    first_arg = get_arg(vm, processus, first_type, 10);
    second_arg = get_arg(vm, processus, second_type, 10);
    third_arg = get_arg(vm, processus, third_type, 10);
    first = get_value(vm, processus, first_type, first_arg);
    second = get_value(vm, processus, second_type, second_arg);
    if (third_type != 3) {
        processus->carry = false; return;
    } sum = first + second + actual_pc;
    REG[third_arg - 1] = vm->arena[((sum) % IDX_MOD) % MEM_SIZE] * 16777216;
    REG[third_arg - 1] += vm->arena[((sum + 1) % IDX_MOD) % MEM_SIZE] * 65536;
    REG[third_arg - 1] += vm->arena[((sum + 2) % IDX_MOD) % MEM_SIZE] * 256;
    REG[third_arg - 1] += vm->arena[((sum + 3) % IDX_MOD) % MEM_SIZE];
    processus->cycle += 25;
}

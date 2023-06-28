/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_or2(vm_t *vm, processus_t *processus, int actual_pc, int *first)
{
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3, first_arg = 0;
    int sum = 0;

    first_arg = get_arg(vm, processus, first_type, 7);
    sum = first_arg + actual_pc;
    if (first_type == 1)
        *first = REG[first_arg - 1];
    if (first_type == 2)
        *first = first_arg;
    if (first_type == 3) {
        *first = vm->arena[((sum) % IDX_MOD) % MEM_SIZE] * 256 * 256 * 256;
        *first += vm->arena[((sum + 1) % IDX_MOD) % MEM_SIZE] * 256 * 256;
        *first += vm->arena[((sum + 2) % IDX_MOD) % MEM_SIZE] * 256;
        *first += vm->arena[((sum + 3) % IDX_MOD) % MEM_SIZE];
    }
}

void function_or(vm_t *vm, processus_t *processus)
{
    int actual_pc = processus->pc, coding_byte = vm->arena[processus->pc + 1];
    int second_type = (coding_byte >> 4) & 3, second_arg = 0, second = 0;
    int first, third_type = (coding_byte >> 2) & 3, third_arg = 0, sum = 0;
    processus->pc += 2; processus->carry = true;
    second_arg = get_arg(vm, processus, second_type, 7);
    third_arg = get_arg(vm, processus, third_type, 7);
    sum = second_arg + actual_pc;
    if (third_type != 1) {
        processus->carry = false; return;
    } function_or2(vm, processus, actual_pc, &first);
    if (second_type == 1)
        second = REG[second_arg - 1];
    if (second_type == 2)
        second = second_arg;
    if (second_type == 3) {
        second = vm->arena[((sum) % IDX_MOD) % MEM_SIZE] * 256 * 256 * 256;
        second += vm->arena[((sum + 1) % IDX_MOD) % MEM_SIZE] * 256 * 256;
        second += vm->arena[((sum + 2) % IDX_MOD) % MEM_SIZE] * 256;
        second += vm->arena[((sum + 3) % IDX_MOD) % MEM_SIZE];
    } REG[third_arg - 1] = first | second; processus->cycle += 6;
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_zjmp(vm_t *vm, processus_t *processus)
{
    int actual_pc = processus->pc;
    int first_arg = 0;

    processus->pc++;
    first_arg = get_arg(vm, processus, 2, 9) - 1;
    if (processus->carry)
        processus->pc = (actual_pc + (first_arg % IDX_MOD)) % MEM_SIZE;
    else
        processus->pc += 3;
    processus->cycle += 20;
}

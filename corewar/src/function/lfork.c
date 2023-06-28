/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_lfork(vm_t *vm, processus_t *processus)
{
    int actual_pc = processus->pc;
    int first_arg = 0;
    size_t i = 0;
    processus->pc += 1;
    first_arg = get_arg(vm, processus, 2, 12);
    for (; vm->processus[i]; i++);
    vm->processus = realloc(vm->processus, sizeof(processus_t *) * (i + 2));
    vm->processus[i] = malloc(sizeof(processus_t));
    vm->processus[i]->pc = actual_pc + first_arg;
    vm->processus[i]->cycle = 0;
    vm->processus[i]->carry = processus->carry;
    vm->processus[i]->is_alive = true;
    for (size_t j = 0; j < REG_NUMBER + 1; j++)
        vm->processus[i]->reg[j] = REG[j];
    vm->processus[i]->reg[1] = REG[1];
    vm->processus[i + 1] = NULL;
    processus->cycle += 1000;
}

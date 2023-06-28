/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_sti2(vm_t *vm, processus_t *processus, instruction_t *i, int sum)
{
    if (i->actual_pc + sum < 0) {
        sum = MEM_SIZE + (i->actual_pc + sum);
        vm->arena[(sum) % MEM_SIZE] = (char)(REG[i->first_arg - 1] >> 24);
        vm->arena[(sum + 1) % MEM_SIZE] = (char)(REG[i->first_arg - 1] >> 16);
        vm->arena[(sum + 2) % MEM_SIZE] = (char)(REG[i->first_arg - 1] >> 8);
        vm->arena[(sum + 3) % MEM_SIZE] = (char)(REG[i->first_arg - 1] & 255);
        vm->color_arena[(sum) % MEM_SIZE] = vm->color_arena[processus->pc];
        vm->color_arena[(sum + 1) % MEM_SIZE] = vm->color_arena[processus->pc];
        vm->color_arena[(sum + 2) % MEM_SIZE] = vm->color_arena[processus->pc];
        vm->color_arena[(sum + 3) % MEM_SIZE] = vm->color_arena[processus->pc];
        return;
    }
    STI(i->actual_pc, (sum)) = (char)(REG[i->first_arg - 1] >> 24);
    STI(i->actual_pc + 1, (sum)) = (char)(REG[i->first_arg - 1] >> 16 & 255);
    STI(i->actual_pc + 2, (sum)) = (char)(REG[i->first_arg - 1] >> 8 & 255);
    STI(i->actual_pc + 3, (sum)) = (char)(REG[i->first_arg - 1] & 255);
    STIC(i->actual_pc, (sum)) = vm->color_arena[processus->pc];
    STIC(i->actual_pc + 1, (sum)) = vm->color_arena[processus->pc];
    STIC(i->actual_pc + 2, (sum)) = vm->color_arena[processus->pc];
    STIC(i->actual_pc + 3, (sum)) = vm->color_arena[processus->pc];
}

void function_sti(vm_t *vm, processus_t *processus)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3;
    int second_type = (coding_byte >> 4) & 3;
    int third_type = (coding_byte >> 2) & 3;
    int sum = 0;

    instruction->actual_pc = processus->pc;
    processus->pc += 2;
    instruction->first_arg = get_arg(vm, processus, first_type, 11);
    instruction->second_arg = get_arg(vm, processus, second_type, 11);
    instruction->third_arg = get_arg(vm, processus, third_type, 11);
    sum = instruction->second_arg + instruction->third_arg;
    if (first_type != 1)
        return;
    function_sti2(vm, processus, instruction, sum);
    processus->cycle += 25;
    free(instruction);
}

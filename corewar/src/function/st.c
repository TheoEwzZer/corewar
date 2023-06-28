/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_st2(vm_t *vm, processus_t *processus, instruction_t *i)
{
    if (i->actual_pc + i->second_arg < 0) {
        i->second_arg = MEM_SIZE + (i->actual_pc + i->second_arg);
        vm->arena[i->second_arg] = (char)(REG[i->first_arg - 1] >> 24);
        vm->arena[i->second_arg + 1] = (char)(REG[i->first_arg - 1] >> 16);
        vm->arena[i->second_arg + 2] = (char)(REG[i->first_arg - 1] >> 8);
        vm->arena[i->second_arg + 3] = (char)(REG[i->first_arg - 1] & 255);
        vm->color_arena[i->second_arg] = vm->color_arena[processus->pc];
        vm->color_arena[i->second_arg + 1] = vm->color_arena[processus->pc];
        vm->color_arena[i->second_arg + 2] = vm->color_arena[processus->pc];
        vm->color_arena[i->second_arg + 3] = vm->color_arena[processus->pc];
        return;
    }
    ST(i->actual_pc, i->second_arg) = (char)(REG[i->first_arg - 1] >> 24);
    ST(i->actual_pc + 1, i->second_arg) = (char)(REG[i->first_arg - 1] >> 16);
    ST(i->actual_pc + 2, i->second_arg) = (char)(REG[i->first_arg - 1] >> 8);
    ST(i->actual_pc + 3, i->second_arg) = (char)(REG[i->first_arg - 1] & 255);
    STC(i->actual_pc, i->second_arg) = vm->color_arena[processus->pc];
    STC(i->actual_pc + 1, i->second_arg) = vm->color_arena[processus->pc];
    STC(i->actual_pc + 2, i->second_arg) = vm->color_arena[processus->pc];
    STC(i->actual_pc + 3, i->second_arg) = vm->color_arena[processus->pc];
}

void function_st(vm_t *vm, processus_t *processus)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));
    int coding_byte = vm->arena[processus->pc + 1];
    int first_type = (coding_byte >> 6) & 3;
    int second_type = (coding_byte >> 4) & 3;

    instruction->actual_pc = processus->pc;
    processus->pc += 2;
    instruction->first_arg = get_arg(vm, processus, first_type, 3);
    instruction->second_arg = get_arg(vm, processus, second_type, 3);
    if (first_type != 1)
        return;
    if (second_type == 1) {
        REG[instruction->second_arg - 1] = REG[instruction->first_arg - 1];
    } else if (second_type == 3) {
        function_st2(vm, processus, instruction);
    }
    processus->cycle += 5;
    free(instruction);
}

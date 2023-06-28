/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

const char *get_player_name(champion_t **champs, long result)
{
    for (size_t i = 0; champs[i]; i++) {
        if (champs[i]->header->prog_number == result) {
            champs[i]->alive = true;
            return champs[i]->header->prog_name;
        }
    }
    return "\0";
}

int get_value(vm_t *vm, processus_t *processus, int arg_type, int arg)
{
    if (arg_type == 1)
        return REG[arg + 1];
    if (arg_type == 2)
        return arg;
    if (arg_type == 3) {
        return vm->arena[((arg + processus->pc) % IDX_MOD) % MEM_SIZE] * 256
        + vm->arena[((arg + processus->pc + 1) % IDX_MOD) % MEM_SIZE];
    }
    return 0;
}

int get_arg2(vm_t *vm, processus_t *processus)
{
    int arg = 0;

    if (vm->arena[processus->pc] < 0) {
        arg = ~vm->arena[processus->pc] * 256 + ~vm->arena[processus->pc + 1];
        arg = -arg;
    } else {
        arg = vm->arena[processus->pc] * 256 + vm->arena[processus->pc + 1];
    }
    processus->pc += 2; return arg;
}

int get_st_arg(vm_t *vm, processus_t *processus)
{
    int arg = 0;

    if (vm->arena[processus->pc] < 0) {
        arg = ~vm->arena[processus->pc] + ~vm->arena[processus->pc + 1] * 256;
        arg = -arg;
    } else {
        arg = vm->arena[processus->pc] + vm->arena[processus->pc + 1] * 256;
    }
    return arg;
}

int get_arg(vm_t *vm, processus_t *processus, int arg_type, int opcode)
{
    int arg = 0;

    if (arg_type == 1) {
        arg = vm->arena[processus->pc];
        processus->pc += 1;
        return arg;
    }
    if (opcode == 3 && arg_type == 3)
        return get_st_arg(vm, processus);
    if (arg_type == 3 || opcode == 9 || opcode == 10
    || opcode == 11 || opcode == 12 || opcode == 14 || opcode == 15)
        return get_arg2(vm, processus);
    if (arg_type == 2) {
        arg = vm->arena[processus->pc] * 256 * 256 * 256
        + vm->arena[processus->pc + 1] * 256 * 256
        + vm->arena[processus->pc + 2] * 256
        + vm->arena[processus->pc + 3];
        processus->pc += 4; return arg;
    }
    return arg;
}

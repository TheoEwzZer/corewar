/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void create_processus(vm_t *vm)
{
    vm->processus = my_calloc(vm->number_of_champion + 1, sizeof(processus_t*));
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        vm->processus[i] = my_calloc(1, sizeof(processus_t));
        vm->processus[i]->carry = false;
        vm->processus[i]->cycle = 0;
        vm->processus[i]->pc = vm->champions[i]->load_address;
        vm->processus[i]->reg[0] = vm->champions[i]->header->prog_number;
        vm->processus[i]->is_alive = true;
    }
}

void execute_processus2(vm_t *vm)
{
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        if (vm->champions[i]->nbr_exec_lives % NBR_LIVE == 0)
            vm->champions[i]->cycle_to_die -= CYCLE_DELTA;
        if (vm->champions[i]->cycle >= vm->champions[i]->cycle_to_die) {
            vm->champions[i]->alive = false;
            check_winner(vm);
        }
        vm->champions[i]->cycle++;
    }
    for (size_t i = 0; vm->processus[i]; i++) {
        if (!vm->processus[i]->is_alive)
            continue;
        if (!vm->processus[i]->cycle) {
            choose_function(vm, vm->processus[i]);
            continue;
        }
        if (vm->processus[i]->cycle > 0)
            vm->processus[i]->cycle--;
    }
}

void execute_processus(vm_t *vm)
{
    int nb_cycles = 1;

    while (42) {
        if (nb_cycles % (int)vm->nbr_cycle == 0)
            dump_memory(vm);
        execute_processus2(vm);
        nb_cycles++;
    }
}

void choose_function(vm_t *vm, processus_t *processus)
{
    char opcode = '\0';
    int opcode_index = 0;
    void (*op_functions[17])(vm_t *, processus_t *) = {
        function_live, function_ld, function_st, function_add,
        function_sub, function_and, function_or, function_xor,
        function_zjmp, function_ldi, function_sti, function_fork,
        function_lld, function_lldi, function_lfork, function_aff,
        NULL
    };
    if (processus->pc >= MEM_SIZE)
        processus->pc = processus->pc % MEM_SIZE;
    opcode = vm->arena[processus->pc];
    while (op_tab[opcode_index].mnemonique) {
        if (op_tab[opcode_index].code == opcode) {
            op_functions[opcode_index](vm, processus);
            return;
        }
        opcode_index++;
    }
    processus->pc++;
}

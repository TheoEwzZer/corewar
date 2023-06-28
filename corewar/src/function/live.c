/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void function_live(vm_t *vm, processus_t *processus)
{
    long result = 0;

    result += (vm->arena[processus->pc + 1] * 256 * 256 * 256);
    result += (vm->arena[processus->pc + 2] * 256 * 256);
    result += (vm->arena[processus->pc + 3] * 256);
    result += (vm->arena[processus->pc + 4]);
    write(1, "The player ", 11);
    my_put_nbr(result);
    write(1, "(", 1);
    my_putstr(get_player_name(vm->champions, result));
    write(1, ") is alive.\n", 12);
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        if (vm->color_arena[processus->pc] == (char)(i + 1)) {
            vm->champions[i]->cycle = 0;
            vm->champions[i]->nbr_exec_lives++;
        }
    }
    processus->cycle += 10;
    change_pc(&processus->pc, 5);
}

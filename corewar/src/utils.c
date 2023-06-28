/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void change_pc(int *pc, int nb)
{
    *pc += nb;
    if (*pc >= MEM_SIZE)
        *pc = *pc % MEM_SIZE;
    if (*pc < 0)
        *pc = MEM_SIZE + *pc;
}

void check_winner(vm_t *vm)
{
    size_t count = 0;
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        if (vm->champions[i]->alive)
            count++;
    }
    if (count != 1) return;
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        if (vm->champions[i]->alive) {
            write(1, "The player ", 11);
            my_put_nbr(vm->champions[i]->header->prog_number);
            write(1, "(", 1);
            my_putstr(vm->champions[i]->header->prog_name);
            write(1, ") has won.\n", 11);
            my_exit(vm, 0);
        }
    }
}

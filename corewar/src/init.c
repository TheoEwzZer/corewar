/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void init_vm(vm_t *vm)
{
    vm->nbr_cycle = 5000;
    vm->color_arena = my_calloc(MEM_SIZE + 1, sizeof(char));
    vm->write_color[0] = NORMAL;
    vm->write_color[1] = RED;
    vm->write_color[2] = YELLOW;
    vm->write_color[3] = GREEN;
    vm->write_color[4] = BLUE;
}

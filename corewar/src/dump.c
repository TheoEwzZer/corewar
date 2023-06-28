/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void print_dump(vm_t *vm, char *str, char color, size_t i, size_t k)
{
    size_t index = (size_t)color;

        for (size_t j = 0; vm->processus[j]; j++) {
        if ((i * 96) + k == (size_t)vm->processus[j]->pc) {
            write(1, MAGENTA, my_strlen(MAGENTA));
            write(1, str, my_strlen(str));
            write(1, NORMAL, 7);
            return;
        }
    }
    write(1, vm->write_color[index], my_strlen(vm->write_color[index]));
    write(1, str, my_strlen(str));
    write(1, NORMAL, 7);
}

void dump_memory(vm_t *vm)
{
    char *str = my_calloc(3, sizeof(char));
    const char *base = "0123456789ABCDEF";
    size_t j = 0;
    sleep(1);
    write(1, "\033[2J\033[1;1H", 10);
    for (size_t i = 0; i < MEM_SIZE / 96; i++) {
        my_putnbr_base((unsigned int)(i * 96), base);
        write(1, "  ", 2);
        str[0] = base[(vm->arena[j] >> 4) & 0xF];
        str[1] = base[vm->arena[j] & 0xF];
        print_dump(vm, str, vm->color_arena[j], i, 0);
        for (size_t k = 1; k < 96; k++) {
            write(1, " ", 1);
            str[0] = base[(vm->arena[k + j] >> 4) & 0xF];
            str[1] = base[vm->arena[k + j] & 0xF];
            print_dump(vm, str, vm->color_arena[k + j], i, k);
        }
        write(1, "\n", 1);
        j += 96;
    }
    free(str);
}

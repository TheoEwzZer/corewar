/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void help(vm_t *vm)
{
    write(1, "USAGE\n", 6);
    write(1, "./corewar [-dump nbr_cycle] [[-n prog_number]", 45);
    write(1, " [-a load_address] prog_name] ...", 33);
    write(1, "\nDESCRIPTION\n", 13);
    write(1, "-dump nbr_cycle dumps the memory after", 38);
    write(1, "the nbr_cycle execution (if the round isn't\n", 44);
    write(1, "already over) with the following format: 32 bytes/line\n", 55);
    write(1, "in hexadecimal (A0BCDEFE1DD3...)\n", 33);
    write(1, "-n prog_number sets the next program's number.", 46);
    write(1, "By default, the first free number\n", 34);
    write(1, "in the parameter order\n", 23);
    write(1, "-a load_address sets the next program's loading address.", 46);
    write(1, "When no address is\n", 19);
    write(1, "specified, optimize the addresses so", 36);
    write(1, "that the processes are as far\n", 30);
    write(1, "away from each other as possible.", 33);
    write(1, "The addresses are MEM_SIZE modulo.\n", 35);
    my_exit(vm, 0);
}

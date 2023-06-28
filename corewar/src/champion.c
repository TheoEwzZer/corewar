/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

void set_address(vm_t *vm)
{
    for (size_t i = 0; i < vm->number_of_champion; i++) {
        if (ADDRESS(i) < 0)
            ADDRESS(i) = (int)(i * (MEM_SIZE / vm->number_of_champion));
    }
}

void define_prog_number(vm_t *vm, char **argv, size_t i, size_t nb_champ)
{
    int tmp = 0;

    vm->n++;
    tmp = my_getnbr(argv[i + 1]);
    for (size_t k = 0; k < 4; k++) {
        if (vm->champions[k]->header->prog_number == tmp)
            my_exit(vm, 84);
    }
    if (tmp < 0)
        my_exit(vm, 84);
    vm->champions[nb_champ]->header->prog_number = tmp;
    i++;
}

void define_address(vm_t *vm, char **argv, size_t i, size_t nb_champ)
{
    vm->a++;
    ADDRESS(nb_champ) = (size_t)my_getnbr(argv[i + 1]);
    if (ADDRESS(nb_champ) >= MEM_SIZE)
        ADDRESS(nb_champ) = ADDRESS(nb_champ) % MEM_SIZE;
    if (ADDRESS(nb_champ) < 0)
        my_exit(vm, 84);
}

void create_champion2(vm_t *vm, char **argv, size_t i, size_t *nb_champ)
{
    if (!my_strcmp(argv[i], "-n")) {
        define_prog_number(vm, argv, i, *nb_champ);
        i++;
    } else if (!my_strcmp(argv[i], "-a")) {
        define_address(vm, argv, i, *nb_champ);
        i++;
    } else {
        if (!is_cor_file(argv[i]))
            return;
        load_core(vm, argv[i], (int)*nb_champ);
        (*nb_champ)++;
    }
}

void create_champion(vm_t *vm, char **argv)
{
    size_t nb_champ = 0;
    for (size_t i = 1; argv[i]; i++)
        check_cli(vm, argv, &i);
    vm->a = 0;
    vm->n = 0;
    for (size_t j = 0; j < 4; j++) {
        vm->champions[j] = malloc(sizeof(champion_t));
        vm->champions[j]->header = malloc(sizeof(header_t));
        vm->champions[j]->header->prog_number = -1;
        vm->champions[j]->cycle = 1;
        vm->champions[j]->cycle_to_die = CYCLE_TO_DIE;
        vm->champions[j]->alive = true;
        vm->champions[j]->nbr_exec_lives = 0;
        ADDRESS(j) = -1;
    }
    set_address(vm);
    for (size_t i = 1; argv[i]; i++)
        create_champion2(vm, argv, i, &nb_champ);
    if (vm->a > vm->number_of_champion || vm->n > vm->number_of_champion)
        my_exit(vm, 84);
}

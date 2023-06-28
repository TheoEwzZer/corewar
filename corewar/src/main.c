/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "vm.h"

bool is_cor_file(char *str)
{
    size_t len = my_strlen(str);

    if (len < 5)
        return false;
    if (str[len - 1] == 'r' && str[len - 2] == 'o'
        && str[len - 3] == 'c' && str[len - 4] == '.')
        return true;
    return false;
}

size_t read_number_of_champion(char **argv)
{
    size_t number_of_champion = 0;

    for (size_t i = 0; argv[i]; i++) {
        if (!is_cor_file(argv[i]))
            continue;
        number_of_champion++;
    }
    return number_of_champion;
}

void load_core(vm_t *vm, char *path, int nb)
{
    int fd = open(path, O_RDONLY);
    char *buffer = my_calloc(MEM_SIZE + 1, sizeof(char)), *buffer_ptr = buffer;
    ssize_t size = 0;
    if (fd == -1) my_exit(vm, 84);
    size = read(fd, buffer, MEM_SIZE);
    if (size <= 0) my_exit(vm, 84);
    my_memset(vm->champions[nb]->header->prog_name, 0, PROG_NAME_LENGTH + 1);
    for (size_t i = 0, j = 0; i < PROG_NAME_LENGTH; i++) {
        if (buffer[i] >= 32 && buffer[i] <= 126)
            vm->champions[nb]->header->prog_name[j++] = buffer[i];
    }
    buffer += HEADER_LENGTH, size -= HEADER_LENGTH;
    for (ssize_t i = ADDRESS(nb), j = 16; j < size && i < MEM_SIZE; i++, j++) {
        vm->arena[i] = buffer[j];
        vm->color_arena[i] = (char)(nb + 1);
    }
    close(fd);
    if (vm->champions[nb]->header->prog_number == -1)
        vm->champions[nb]->header->prog_number = nb + 1;
    free(buffer_ptr);
}

void create_arena(vm_t *vm, char **argv)
{
    vm->arena = my_calloc(MEM_SIZE + 1, sizeof(char));
    vm->champions = my_calloc(5, sizeof(champion_t *));
    create_champion(vm, argv);
    create_processus(vm);
}

int main(int argc, char **argv)
{
    vm_t *vm = malloc(sizeof(vm_t));

    init_vm(vm);
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        help(vm);
    if (argc < 2)
        return 84;
    for (size_t i = 0; argv[i]; i++) {
        if (!my_strcmp(argv[i], "-dump") && argv[i + 1])
            vm->nbr_cycle = (size_t)my_getnbr(argv[i + 1]);
    }
    vm->number_of_champion = read_number_of_champion(argv);
    if (vm->number_of_champion > 4)
        my_exit(vm, 84);
    create_arena(vm, argv);
    execute_processus(vm);
    return 0;
}

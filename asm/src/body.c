/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

void write_direct(asm_t *my_asm, size_t i, size_t k, off_t pos_label)
{
    unsigned int nb = (unsigned int)my_getnbr(FINALTAB[i][k]);
    unsigned short int nb2 = (unsigned short int)nb;
    size_t direct_size = DIR_SIZE;

    nb2 = (unsigned short int)((nb2 << 8) | (nb2 >> 8));
    nb = swap_uint32(nb);
    if (my_asm->function_code == 9 || my_asm->function_code == 10
        || my_asm->function_code == 11 || my_asm->function_code == 12
        || my_asm->function_code == 14 || my_asm->function_code == 15)
        direct_size = 2;
    if (FINALTAB[i][k][1] == LABEL_CHAR) {
        stock_label(my_asm, FINALTAB[i][k], pos_label);
        for (size_t j = 0; j < direct_size; j++)
            write(my_asm->fd, "\000", 1);
    } else {
        if (direct_size == 2)
            write(my_asm->fd, &nb2, sizeof(short int));
        else
            write(my_asm->fd, &nb, sizeof(nb));
    }
}

void write_body2(asm_t *my_asm, size_t i)
{
    for (size_t k = 0; FINALTAB[i][k]; k++) {
        if (FINALTAB[i][k][my_strlen(FINALTAB[i][k]) - 1] == LABEL_CHAR) {
            stock_label_ref(my_asm, FINALTAB[i][k], my_asm->fd);
            continue;
        }
        loop(my_asm, i, &k);
    }
}

void write_body(asm_t *my_asm, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *buffer = my_calloc(MEM_SIZE, sizeof(char));
    ssize_t size = read(fd, buffer, MEM_SIZE);
    char **tab = my_str_to_word_delim(buffer, '\n');
    FINALTAB = my_calloc(MEM_SIZE, sizeof(char **));

    if (!size || size == -1)
        exit(84);
    for (size_t i = 0; tab[i]; i++)
        FINALTAB[i] = my_str_to_tab(tab[i]);
    verify_tab(my_asm);
    for (size_t i = 0; FINALTAB[i]; i++)
        write_body2(my_asm, i);
    write_labels(my_asm);
    write_prog_size(my_asm, my_asm->fd);
    close(fd);
}

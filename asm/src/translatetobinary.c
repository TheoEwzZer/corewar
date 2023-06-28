/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

void write_args(asm_t *my_asm, size_t i, size_t k, off_t pos_label)
{
    int nb = my_getnbr(FINALTAB[i][k]);
    unsigned short int nb2 = (unsigned short int)nb;

    nb2 = (unsigned short int)((nb2 << 8) | (nb2 >> 8));
    if (FINALTAB[i][k][0] == REGISTER_CHAR) {
        write(my_asm->fd, &nb, sizeof(char));
        return;
    }
    if (FINALTAB[i][k][0] == DIRECT_CHAR) {
        write_direct(my_asm, i, k, pos_label);
    } else {
        if (FINALTAB[i][k][0] == LABEL_CHAR) {
            stock_label(my_asm, FINALTAB[i][k], pos_label);
            write(my_asm->fd, "\000\000", 2);
        } else {
            write(my_asm->fd, &nb2, sizeof(short int));
        }
    }
}

void coding_args(asm_t *my_asm, size_t i, size_t *k, off_t pos_label)
{
    while (FINALTAB[i][*k]) {
        write_args(my_asm, i, *k, pos_label);
        (*k)++;
    }
}

void find_coding_byte(asm_t *my_asm, size_t i,
    size_t k, unsigned char *coding_byte)
{
    if (FINALTAB[i][k][0] == REGISTER_CHAR)
        *coding_byte = (unsigned char)(*coding_byte + 1);
    else if (FINALTAB[i][k][0] == DIRECT_CHAR)
        *coding_byte = (unsigned char)(*coding_byte + 2);
    else
        *coding_byte = (unsigned char)(*coding_byte + 3);
    *coding_byte = (unsigned char)(*coding_byte << 2);
}

void coding_byte(asm_t *my_asm, size_t i, size_t *k)
{
    size_t k2 = 0, count = 0;
    unsigned char coding_byte = 0;

    k2 = *k;
    for (; FINALTAB[i][k2]; k2++, count++)
        find_coding_byte(my_asm, i, k2, &coding_byte);
    for (; count < 3; count++)
        coding_byte = (unsigned char)(coding_byte << 2);
    write(my_asm->fd, &coding_byte, sizeof(unsigned char));
}

void loop(asm_t *my_asm, size_t i, size_t *k)
{
    off_t pos_label = lseek(my_asm->fd, 0, SEEK_CUR);

    for (size_t j = 0; op_tab[j].mnemonique; j++) {
        if (my_strcmp(FINALTAB[i][*k], op_tab[j].mnemonique))
            continue;
        my_asm->function_code = op_tab[j].code;
        write(my_asm->fd, &my_asm->function_code, sizeof(char));
        (*k)++;
        if (j != 0 && j != 8 && j != 11 && j != 14)
            coding_byte(my_asm, i, k);
        coding_args(my_asm, i, k, pos_label);
        break;
    }
}

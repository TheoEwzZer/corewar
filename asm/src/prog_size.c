/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

#include <stdint.h>

unsigned int swap_uint32(unsigned int x)
{
    return ((x >> 24) & 0xff) |
        ((x << 8) & 0xff0000) |
        ((x >> 8) & 0xff00) |
        ((x << 24) & 0xff000000);
}

short int swap_uint16(short int x)
{
    return (short int)(((x >> 8) & 0xff) | ((x << 8) & 0xff00));
}

void write_prog_size(asm_t *my_asm, int fd)
{
    off_t file_size = lseek(fd, 0, SEEK_END);
    ssize_t bytes_written = 0;

    if (file_size == -1)
        exit(84);
    lseek(fd, PROG_NAME_LENGTH + 8, SEEK_SET);
    PROG_SIZE = (int)file_size - 2184 - 8;
    if (PROG_SIZE < 0)
        exit(84);
    PROG_SIZE = (int)(swap_uint32((unsigned int)PROG_SIZE));
    bytes_written = write(fd, &PROG_SIZE, sizeof(PROG_SIZE));
    if (bytes_written == -1)
        exit(84);
}

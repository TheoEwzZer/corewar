/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

int display_help(void)
{
    write(1, "USAGE\n./asm file_name[.s]\n", 26);
    write(1, "comment\nfile_name in assembly language ", 39);
    write(1, "to be converted into file_name.cor, an executable ", 50);
    write(1, "in the virtual Machine.\n", 24);
    return 0;
}

int start_asm(asm_t *my_asm, char **argv)
{
    my_asm->name = s_to_cor(argv[1]);
    if (my_asm->fd < 0)
        exit(84);
    write_header(my_asm, argv);
    write_body(my_asm, argv);
    return 0;
}

int main(int argc, char **argv)
{
    asm_t *my_asm = malloc(sizeof(asm_t));
    my_asm->header = malloc(sizeof(header_t));
    my_asm->label = malloc(sizeof(label_t *));
    my_asm->label[0] = NULL;
    LABEL_REF = malloc(sizeof(label_t *));
    LABEL_REF[0] = NULL;
    if (argc != 2)
        return 84;
    if (!my_strcmp(argv[1], "-h"))
        return display_help();
    return start_asm(my_asm, argv);
}

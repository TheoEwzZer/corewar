/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

char *s_to_cor(char *file_name)
{
    char *cor_file_name = my_calloc(my_strlen(file_name) + 3, sizeof(char));
    char *dot = NULL;
    char *last_slash = my_strrchr(file_name, '/');

    if (!last_slash)
        my_strcpy(cor_file_name, file_name);
    else
        my_strcpy(cor_file_name, last_slash + 1);
    dot = my_strrchr(cor_file_name, '.');
    if (dot && !my_strcmp(dot, ".s"))
        my_strcpy(dot, ".cor");
    else
        exit(84);
    return cor_file_name;
}

void read_header(char *file, char *buffer)
{
    int fd = open(file, O_RDONLY);

    if (fd < 0 || !buffer || read(fd, buffer, HEADER_LENGTH) < 0)
        exit(84);
    close(fd);
}

void parse_header2(asm_t *my_asm, char *comment)
{
    char *comment_v = NULL;
    char *comment_e = NULL;

    comment_v = comment + my_strlen(COMMENT_CMD_STRING);
    while (*comment_v && (*comment_v == ' ' || *comment_v == '\t'))
        comment_v++;
    if (*comment_v != '\"')
        exit(84);
    comment_v++;
    comment_e = my_strstr(comment_v, "\"");
    if (!comment_v || !comment_e || comment_e - comment_v > COMMENT_LENGTH)
        exit(84);
    *comment_e = '\0';
    if (*(++comment_e) && *comment_e != '\n')
        exit(84);
    my_strncpy(my_asm->header->comment, comment_v, COMMENT_LENGTH);
}

void parse_header(asm_t *my_asm, char *buffer)
{
    char *name = NULL, *name_value, *name_end = NULL;
    char *comment = NULL;
    name = my_strstr(buffer, NAME_CMD_STRING);
    comment = my_strstr(buffer, COMMENT_CMD_STRING);
    if (!name || !comment || name > comment)
        exit(84);
    name_value = name + my_strlen(NAME_CMD_STRING);
    while (*name_value && (*name_value == ' ' || *name_value == '\t'))
        name_value++;
    if (*name_value != '\"')
        exit(84);
    name_value++;
    name_end = my_strstr(name_value, "\"");
    if (!name_value || !name_end || name_end - name_value > PROG_NAME_LENGTH)
        exit(84);
    *name_end = '\0';
    if (*(++name_end) && *name_end != '\n')
        exit(84);
    my_strncpy(my_asm->header->prog_name, name_value, PROG_NAME_LENGTH);
    parse_header2(my_asm, comment);
}

void write_header(asm_t *my_asm, char **argv)
{
    char *buffer = my_calloc(sizeof(char), HEADER_LENGTH);
    ssize_t bytes_written = 0;
    unsigned int magic_number = (unsigned int)(swap_uint32(COREWAR_EXEC_MAGIC));

    read_header(argv[1], buffer);
    parse_header(my_asm, buffer);
    my_asm->fd = open(my_asm->name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    bytes_written = write(my_asm->fd, &magic_number, sizeof(magic_number));
    if (bytes_written < 0)
        exit(84);
    write(my_asm->fd, &my_asm->header->prog_name, PROG_NAME_LENGTH);
    write(my_asm->fd ,"\0\0\0\0\0\0\0\0", 8);
    write(my_asm->fd, &my_asm->header->comment, COMMENT_LENGTH);
    write(my_asm->fd ,"\0\0\0\0", 4);
    free(buffer);
}

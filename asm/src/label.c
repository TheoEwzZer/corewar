/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

void write_labels2(asm_t *my_asm, size_t i)
{
    short int code = 0;
    unsigned int code2 = 0;

    for (size_t k = 0; LABEL_REF[k]; k++) {
        if (my_strcmp(my_asm->label[i]->name + 1, LABEL_REF[k]->name))
            continue;
        if (my_asm->label[i]->opcode == 13) {
            code2 = (unsigned int)(LABEL_REF[k]->pos - my_asm->label[i]->pos);
            code2 = swap_uint32(code2);
            lseek(my_asm->fd, my_asm->label[i]->label_pos, SEEK_SET);
            write(my_asm->fd, &code2, sizeof(code2));
            return;
        }

        code = (short int)(LABEL_REF[k]->pos - my_asm->label[i]->pos);
        code = swap_uint16(code);
        lseek(my_asm->fd, my_asm->label[i]->label_pos, SEEK_SET);
        write(my_asm->fd, &code, sizeof(code));
    }
}

void write_labels(asm_t *my_asm)
{
    for (size_t i = 0; my_asm->label[i]; i++)
        write_labels2(my_asm, i);
}

void stock_label_ref(asm_t *my_asm, char *str, int fd)
{
    size_t label_len = 0;

    for (; LABEL_REF[label_len]; label_len++);
    LABEL_REF[label_len] = malloc(sizeof(label_t));
    LABEL_REF = realloc(LABEL_REF, sizeof(label_t *) * (label_len + 2));
    if (!LABEL_REF)
        return;
    LABEL_REF[label_len + 1] = NULL;
    LABEL_REF[label_len]->pos = lseek(fd, 0, SEEK_CUR);
    LABEL_REF[label_len]->name = my_strdup(str);
    LABEL_REF[label_len]->name[my_strlen(str) - 1] = '\0';
    LABEL_REF[label_len]->label_pos = 0;
}

void stock_label(asm_t *my_asm, char *str, off_t pos_label)
{
    size_t label_len = 0;

    for (; my_asm->label[label_len]; label_len++);
    my_asm->label[label_len] = malloc(sizeof(label_t));
    my_asm->label = realloc(my_asm->label, sizeof(label_t *) * (label_len + 2));
    if (!my_asm->label)
        return;
    my_asm->label[label_len + 1] = NULL;
    my_asm->label[label_len]->pos = pos_label;
    my_asm->label[label_len]->name = my_strdup(str);
    my_asm->label[label_len]->opcode = my_asm->function_code;
    if (my_asm->label[label_len]->name[0] == DIRECT_CHAR)
        my_asm->label[label_len]->name++;
    my_asm->label[label_len]->label_pos = lseek(my_asm->fd, 0, SEEK_CUR);
    if (my_asm->label[label_len]->name[my_strlen(str) - 1] == SEPARATOR_CHAR)
        my_asm->label[label_len]->name[my_strlen(str) - 1] = '\0';
}

/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

void skip_delimiter(char *str, size_t *i, char delimiter)
{
    while (str[*i] == delimiter)
        (*i)++;
}

size_t nb_delim(char *str, char delim)
{
    size_t nb = 0;

    for (size_t i = 0; str[i]; i++) {
        if (str[i] == delim)
            nb++;
    }
    return nb;
}

char **my_str_to_word_delim(char *str, char delimiter)
{
    char **array = my_calloc(nb_delim(str, delimiter) + 2, sizeof(char *));
    size_t i = 0, x = 0, y = 0;
    array[x] = my_calloc(my_strlen(str) + 1, sizeof(char));
    skip_delimiter(str, &i, delimiter);
    for (; str[i]; i++) {
        if (str[i] == delimiter) {
            skip_delimiter(str, &i, delimiter);
            array[x][y] = '\0';
            x++;
            y = 0;
            array[x] = my_calloc(my_strlen(str) + 1, sizeof(char));
        }
        array[x][y] = str[i];
        y++;
    }
    array[x][y] = '\0';
    array[x + 1] = NULL;
    if (!my_strcmp(array[x], "\0"))
        array[x] = NULL;
    return array;
}

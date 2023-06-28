/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar
*/

#include "asm.h"

char **my_str_to_tab(char *str)
{
    const char *delimiters = " \t,";
    char **tokens = NULL;
    size_t token_count = 0;
    char *token = my_strtok(str, delimiters);

    while (token) {
        if (*token == COMMENT_CHAR)
            break;
        tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
        if (!tokens)
            exit(84);
        tokens[token_count] = my_strdup(token);
        token_count++;
        token = my_strtok(NULL, delimiters);
    }
    tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
    if (!tokens)
        exit(84);
    tokens[token_count] = NULL;
    return tokens;
}

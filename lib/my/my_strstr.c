/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** Reproduce the behavior of the strstr function.
*/

int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);

#include <stddef.h>

char *my_strstr(const char *haystack, const char *needle)
{
    size_t i = 0, j = 0, k = 0;

    for (; haystack[i]; i++) {
        j = i;
        k = 0;
        while (needle[k] && haystack[j] == needle[k]) {
            j++;
            k++;
        }
        if (!needle[k])
            return (char *)&haystack[i];
    }
    return NULL;
}

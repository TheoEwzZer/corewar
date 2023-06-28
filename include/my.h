/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H_

    #define MY_H_

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdlib.h>

char **my_str_to_word_array(char const *str);
char *increment_str1(int count, char *str_tmp);
char *increment_str2(int count, char *str_tmp, int *j);
char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *s, int c);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strrchr(const char *s, int c);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *str, const char *delim);
char *my_strupcase(char *str);
int my_char_is_space(char c);
int my_char_isnum(char str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_compute_square_root2(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_is_prime2(int nb);
int my_isneg(int n);
int my_put_ptr(unsigned int nbr, int count);
int my_putchar(char c);
void my_putnbr_base(unsigned int nbr, const char *base);
int my_putstr(char const *str);
int my_showstr(char *str);
int my_str_isalpha(char *str);
int my_str_islower(char const *str);
int my_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp_ignore_case(char const *s1, char const *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
int my_swapstr(char *a, char *b);
unsigned int my_strlen(char const *str);
unsigned int my_strlen_double(char *const *str);
void *my_calloc(size_t nmemb, size_t size);
void *my_memset(void *s, int c, size_t n);
void my_put_nbr(long n);
void my_show_word_array(char *const *tab);
void my_sort_int_array(int *array, int size);
void my_swap(int *a, int *b);
void my_swap_char(char **a, char **b);

#endif /* MY_H_ */

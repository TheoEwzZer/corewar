/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

int my_putchar(char c);

void my_put_nbr(long n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + n % 10);
}

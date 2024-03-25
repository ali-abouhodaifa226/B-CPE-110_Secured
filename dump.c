/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** dump
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

void my_putnbr(unsigned int nb)
{
    if (nb < 10)
        return my_putchar(nb + '0');
    my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
}

void print_bucket(bucket_t *bucket, int i)
{
    my_putchar('[');
    my_putnbr(i);
    my_putstr("]:");
    for (int j; bucket != NULL; j++) {
        my_putstr("\n> ");
        my_putnbr(bucket->key);
        my_putstr(" - ");
        my_putstr(bucket->value);
        bucket = bucket->next;
    }
    my_putchar('\n');
}

void ht_dump(hashtable_t *ht)
{
    bucket_t *bucket = NULL;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        bucket = ht->bucket[i];
        print_bucket(bucket, i);
    }
}

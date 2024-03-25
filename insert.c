/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** insert
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int size_nb_str(int nb)
{
    int i = 0;
    int d = 1;

    if (nb == 0)
        return 1;
    for (; d <= nb; i++)
        d *= 10;
    return i;
}

char *int_to_str(int nb)
{
    int len_nb = size_nb_str(nb);
    char *str = malloc((len_nb + 1) * sizeof(char));
    int mod;

    str[len_nb] = '\0';
    for (int i = len_nb - 1; i >= 0; i--) {
        mod = nb % 10;
        str[i] = '0' + mod;
        nb = (nb - mod) / 10;
    }
    return str;
}

void push(bucket_t **bucket, int key, char *value)
{
    bucket_t *temp = malloc(sizeof(bucket_t));

    temp->key = key;
    temp->value = value;
    temp->next = *bucket;
    *bucket = temp;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hash_key;
    int index;
    bucket_t *bucket;

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    hash_key = ht->hash(key, my_strlen(key));
    index = (uint32_t)(hash_key) % ht->len;
    bucket = ht->bucket[index];
    push(&bucket, hash_key, value);
    ht->bucket[index] = bucket;
    return 0;
}

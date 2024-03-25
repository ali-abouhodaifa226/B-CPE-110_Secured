/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaif
** File description:
** hashtable
*/

#include "my.h"

hashtable_t *new_hashtable(int(*hash)(char *, int), int len)
{
    hashtable_t *ht;

    if (hash == NULL || len < 0)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    ht->hash = hash;
    ht->bucket = malloc((len + 1) * sizeof(NULL));
    for (int i = 0; i < len + 1; i++)
        ht->bucket[i] = NULL;
    ht->len = len;
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    bucket_t *destroyed = NULL;
    bucket_t *next = NULL;

    if (ht == NULL || ht->bucket == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        destroyed = ht->bucket[i];
        while (destroyed != NULL) {
            next = destroyed->next;
            free(destroyed);
            destroyed = next;
        }
    }
    free(ht->bucket);
    free(ht);
}

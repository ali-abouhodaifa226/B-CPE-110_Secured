/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** delete
*/

#include "my.h"

int delete(bucket_t **bucket, int hash_key)
{
    bucket_t *temp = *bucket;
    bucket_t *destroyed = *bucket;

    if (temp->key == hash_key) {
        *bucket = destroyed->next;
        free(destroyed);
        return 0;
    }
    while (temp->next != NULL && temp->next->key != hash_key)
        temp = temp->next;
    if (temp->next != NULL) {
        destroyed = temp->next;
        temp->next = destroyed->next;
        free(destroyed);
        return 0;
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_key;
    int index;
    bucket_t *bucket;

    if (ht == NULL || key == NULL)
        return 84;
    hash_key = ht->hash(key, my_strlen(key));
    index = (uint32_t)(hash_key) % ht->len;
    bucket = ht->bucket[index];
    if (delete(&bucket, hash_key) == 84)
        return 84;
    ht->bucket[index] = bucket;
    return 0;
}

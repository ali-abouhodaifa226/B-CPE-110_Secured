/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** search
*/

#include "my.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_key;
    bucket_t *bucket;

    if (ht == NULL || key == NULL)
        return NULL;
    hash_key = ht->hash(key, my_strlen(key));
    bucket = ht->bucket[(uint32_t)(hash_key) % ht->len];
    while (bucket != NULL) {
        if (bucket->key == hash_key)
            return bucket->value;
        bucket = bucket->next;
    }
    return NULL;
}

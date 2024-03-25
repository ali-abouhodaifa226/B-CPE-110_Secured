/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** replace
*/

#include "my.h"

int replace(bucket_t *bucket, int hash_key, char *value)
{
    while (bucket != NULL) {
        if (bucket->key == hash_key) {
            bucket->value = value;
            return 1;
        }
        bucket = bucket->next;
    }
    return 0;
}

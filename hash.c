/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-ali.abouhodaifa
** File description:
** hash
*/

#include "my.h"

int hash(char *key, int len)
{
    int new_hash = 0;

    for (int i = 0; i < len; i++)
        new_hash = key[i] + (new_hash << 6) + (new_hash << 16) - new_hash;
    return new_hash;
}

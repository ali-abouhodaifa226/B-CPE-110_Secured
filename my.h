/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my
*/


#ifndef MY_H_
    #define MY_H_
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include "hashtable.h"
int my_strlen(char *str);
int replace(bucket_t *bucket, int hash_key, char *value);
#endif /* !MY_H_ */

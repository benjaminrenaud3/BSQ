/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int number_lign(map_t *map);
int number_first_lign(map_t *map);
int verify_first_lign(map_t *map);
void init_prog(map_t *map);
int check_error(int argc, char **argv, int fd);
int algo(map_t *map, int *cpt, int temp);
int transform_int_string(map_t *map, int *cpt);
char *buff_withx(map_t *map);
void transform_string(map_t *map, int cpt);
void change_string(map_t *map);
int verify_column(map_t *map);

#endif

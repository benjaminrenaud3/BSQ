/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** fonction basique
*/

#include "my.h"
#include "struct.h"

int verify_first_lign(map_t *map)
{
	int cpt = 0;
	while (map->buff[cpt] != '\n') {
		if (map->buff[cpt] == '.') {
			map->buff[cpt] = 'x';
			return (0);
		}
		cpt += 1;
	}
	return (0);
}

int verify_column(map_t *map)
{
	int cpt = 0;
	while (map->buff[cpt] != '\0') {
		if (map->buff[cpt] == '.') {
			map->buff[cpt] = 'x';
			return (0);
		}
		cpt += 1;
	}
	return (0);
}

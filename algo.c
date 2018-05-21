/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** algo
*/

#include "my.h"
#include "struct.h"

int algo(map_t *map, int *cpt, int temp)
{
	temp = map->str[*cpt - 1];
	if (map->str[*cpt - map->length_lign] < temp)
		temp = map->str[*cpt - map->length_lign];
	else if (map->str[*cpt - map->length_lign - 1] < temp)
		temp = map->str[*cpt - map->length_lign - 1];
	temp += 1;
	return (temp);
}
int transform_int_string(map_t *map, int *cpt)
{
	int temp = 0;
	if (map->buff[*cpt] == '\n' || map->buff[*cpt] == 'o')
		temp = 0;
	else if (map->buff[*cpt - 1] == '\n') {
		if (map->buff[*cpt] == '.')
			temp = 1;
		else
			temp = 0;
	}
	else
		temp = algo(map, cpt, temp);
	if (temp > map->max_value) {
		map->max_value = temp;
		map->pos = *cpt;
	}
	return (temp);
}

char *buff_withx(map_t *map)
{
	int cpt = 1;
	int cpt2 = 0;
	map->buff[map->pos] = 'x';
	while (cpt2 < map->max_value) {
		map->buff[map->pos - cpt2] = 'x';
		cpt2 += 1;
	}
	cpt2 = 0;
	while (cpt < map->max_value) {
		cpt2 = 0;
		map->buff[map->pos - cpt * map->length_lign] = 'x';
		while (cpt2 < map->max_value) {
			map->buff[map->pos - cpt
			* map->length_lign - cpt2] = 'x';
			cpt2 += 1;
		}
		cpt += 1;
	}
	return (map->buff);
}

void transform_string(map_t *map, int cpt)
{
	while (cpt != map->length_array) {
		map->str[cpt] = transform_int_string(map, &cpt);
		cpt += 1;
	}
	cpt = 0;
	while (cpt != map->length_array)
		cpt += 1;
	map->buff = buff_withx(map);
}

void change_string(map_t *map)
{
	int cpt = 0;

	while (map->buff[cpt] != '\0') {
		if (map->buff[cpt] != '.')
			map->str[cpt] = 0;
		else
			map->str[cpt] = 1;
		cpt += 1;
	}
	cpt = 0;
	while (map->buff[cpt] != '\n') {
		if (map->buff[cpt] == '.')
			map->str[cpt] = 1;
		else
			map->str[cpt] = 0;
		cpt += 1;
	}
	transform_string(map, cpt);
}

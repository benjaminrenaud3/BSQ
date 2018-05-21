/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** fonction basique
*/

#include "my.h"
#include "struct.h"

int number_lign(map_t *map)
{
	int cpt = 0;
	while (map->buff[cpt] != '\n') {
		cpt += 1;
	}
	return (cpt);
}

int number_first_lign(map_t *map)
{
	map->first_lign = 0;
	while (map->buff[map->first_lign] != '\n') {
		map->first_lign += 1;
	}
	return (map->first_lign);
}

void init_prog(map_t *map)
{
	map->max_value = 0;
	if (map->buff[0] == '1' && map->buff[1] == '\n') {
		map->first_lign = number_first_lign(map) + 1;
		map->buff += map->first_lign;
		verify_first_lign(map);
	}
	else if (map->buff[number_first_lign(map) + 2] == '\n') {
		map->first_lign = number_first_lign(map) + 1;
		map->buff += map->first_lign;
		verify_column(map);
	}
	else {
		map->first_lign = number_first_lign(map) + 1;
		map->buff += map->first_lign;
		map->length_lign = number_lign(map) + 1;
		map->buff[map->length_array] = '\0';
		change_string(map);
	}
}

int check_error(int argc, char **argv, int fd)
{
	if (argc != 2)
		return (84);
	else if (open(argv[1], O_RDONLY) == -1)
		return (84);
	else
		return (0);
}

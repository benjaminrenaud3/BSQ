/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** main
*/

#include "my.h"
#include "struct.h"

int my_strlen(char *c)
{
	int cpt = 0;
	while (c[cpt] != '\0') {
		cpt += 1;
	}
	return (cpt);
}
int main(int argc, char **argv)
{
	int error = 0;
	int fd = 0;
	int nb = 0;

	error = check_error(argc, argv, fd);
	if (error == 84)
		return (84);
	struct stat *map_stat = malloc(sizeof(struct stat));
	map_t *map = malloc(sizeof(map_t));
	fd = open(argv[1], O_RDONLY);
	stat(argv[1], map_stat);
	map->length_array = map_stat->st_size + 1;
	map->buff = malloc(sizeof(char) * (map->length_array) + 1);
	map->str = malloc(sizeof(int) * (map_stat->st_size + 1));
	nb = read(fd, map->buff, map_stat->st_size + 1);
	if (nb <= 0)
		return (84);
	init_prog(map);
	write(1, map->buff, my_strlen(map->buff));
	return (0);
}

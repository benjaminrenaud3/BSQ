/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** struct for the game
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct map_s {
	char *buff;
	int *str;
	int length_lign;
	int length_array;
	int pos;
	int max_value;
	int first_lign;
}map_t;

#endif

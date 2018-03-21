/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** main
*/

#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

int main(int ac, char **av)
{
	if (ac >= 4 && !strcasecmp(av[3], "ncurses"))
		display_select(NULL, true);
	if (ac >= 3) {
		if (!lem_start(av[1], atoi(av[2]))) {
			if (ac >= 4 && !strcasecmp(av[3], "ncurses"))
				endwin();
			return (EXT_SUCCESS);
		}
	}
	return (EXT_FAILURE);
}

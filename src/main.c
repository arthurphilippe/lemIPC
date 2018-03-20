/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

int main(int ac, char **av)
{
	if (ac == 3) {
		lem_start(av[1], atoi(av[2]));
		return (EXT_SUCCESS);
	}
	return (EXT_FAILURE);
}

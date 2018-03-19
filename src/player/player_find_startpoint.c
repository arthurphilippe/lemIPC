/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_find_startpoint
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lemipc.h"

static int get_rand(int modulo)
{
	return (rand() % modulo);
}

static void chose_side(int *vector)
{
	if (get_rand(2) % 2 == 0) {
		*vector = 1;
	} else {
		*vector = 18;
	}
}

static void randomise_placement(ivector_t *pos)
{
	static int i = 0;

	if (i == 0) {
		srandom(time(NULL) * getpid());
		i += 1;
	}
	if (get_rand(2) % 2 == 0) {
		chose_side(&pos->v_y);
		pos->v_x = get_rand(19);
	} else {
		chose_side(&pos->v_x);
		pos->v_y = get_rand(19);
	}
}

/*
** TODO: infinite-loop safety
*/
ivector_t player_find_startpoint(ipcs_t *ipcs)
{
	ivector_t pos;

	do {
		randomise_placement(&pos);
	} while (!player_move_to(ipcs, &pos, pos));
	printf("[player] placed at %d, %d\n", pos.v_x, pos.v_y);
	return (pos);
}

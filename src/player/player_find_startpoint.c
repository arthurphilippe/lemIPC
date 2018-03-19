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

static void change_vector(ivector_t *pos)
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
**	1 is host
*/
ivector_t player_find_startpoint(ipcs_t *ipcs)
{
	ivector_t pos;

	if (ipcs->i_gpid == 1) {
		pos = (ivector_t) {get_rand(19), get_rand(19)};
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_y += 1;
		}
	} else if (ipcs->i_gpid == 2) {
		pos = (ivector_t) {get_rand(19), get_rand(19)};
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_x += 1;
		}
	} else {
		printf("stpt 3\n");
		change_vector(&pos);
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_x += 1;
		}
	}
	printf("[player] placed at %d, %d\n", pos.v_x, pos.v_y);
	return (pos);
}

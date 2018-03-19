/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_find_startpoint
*/

#include <stdio.h>
#include "lemipc.h"

ivector_t player_find_startpoint(ipcs_t *ipcs)
{
	ivector_t pos;

	if (ipcs->i_gpid == 1) {
		pos = (ivector_t) {1, 1};
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_y += 1;
		}
	} else if (ipcs->i_gpid == 2) {
		pos = (ivector_t) {1, 19};
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_x += 1;
		}
	} else {
		printf("stpt 3\n");
		pos = (ivector_t) {1, 19};
		while (!player_move_to(ipcs, &pos, pos)) {
			pos.v_x += 1;
		}
	}
	printf("[player] placed at %d, %d\n", pos.v_x, pos.v_y);
	return (pos);
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_foe_find
*/

#include <math.h>
#include "lemipc.h"

static int get_dist(ivector_t a, ivector_t b)
{
	int sq1 = b.v_x - a.v_x;
	int sq2 = b.v_y - a.v_y;

	sq1 *= sq1;
	sq2 *= sq2;
	return (sqrtl(sq1 + sq2));
}

static void update_closest(ivector_t *pos, int *dist,
				uint curr_index, ivector_t player_pos)
{
	ivector_t curr_pos;
	int curr_dist;

	curr_pos.v_x = curr_index / BOARD_SIDE;
	curr_pos.v_y = curr_index % BOARD_SIDE;
	curr_dist = get_dist(player_pos, curr_pos);
	if (*dist == 0 || curr_dist < *dist) {
		*dist = curr_dist;
		*pos = curr_pos;
	}
}

ivector_t shm_foe_find(ipcs_t *ipcs, ivector_t player_pos)
{
	ivector_t pos = {-1, -1};
	int dist = 0;

	for (uint i = 0; i < BOARD_SIZE; i += 1) {
		if (ipcs->i_shmsg[i] != POS_EMPTY
			&& ipcs->i_shmsg[i] != ipcs->i_gpid + '0')
			update_closest(&pos, &dist, i, player_pos);
	}
	return (pos);
}

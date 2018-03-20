/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_barycentre_find
*/

#include "lemipc.h"

/*
** Return the position associated with the barycentre of all
** players on the map from a specific team.
*/
ivector_t shm_barycentre_find_target(ipcs_t *ipcs, int target)
{
	ivector_t sum = {0, 0};
	uint count = 0;

	for (uint i = 0; i < BOARD_SIZE; i += 1) {
		if (ipcs->i_shmsg[i] != POS_EMPTY
			&& ipcs->i_shmsg[i] == target + '0') {
			sum.v_x += (i + 1) / BOARD_SIDE;
			sum.v_y += (i + 1) % BOARD_SIDE;
			count += 1;
		}
	}
	if (count) {
		sum.v_x /= count;
		sum.v_y /= count;
	}
	return (sum);
}

/*
** Return the position associated with the barycentre of all
** players on the map excluding the current team.
*/
ivector_t shm_barycentre_find(ipcs_t *ipcs)
{
	ivector_t sum = {0, 0};
	uint count = 0;

	for (uint i = 0; i < BOARD_SIZE; i += 1) {
		if (ipcs->i_shmsg[i] != POS_EMPTY
			&& ipcs->i_shmsg[i] != ipcs->i_gpid + '0') {
			sum.v_x += (i + 1) / BOARD_SIDE;
			sum.v_y += (i + 1) % BOARD_SIDE;
			count += 1;
		}
	}
	if (count) {
		sum.v_x /= count;
		sum.v_y /= count;
	}
	return (sum);
}

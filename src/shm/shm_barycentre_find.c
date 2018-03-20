/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_barycentre_find
*/

#include "lemipc.h"

ivector_t shm_barycentre_find(ipcs_t *ipcs)
{
	ivector_t sum = {0, 0};
	uint count = 0;

	for (uint i = 0; i < BOARD_SIZE; i += 1) {
		if (ipcs->i_shmsg[i] != POS_EMPTY) {
			sum.v_x += i / BOARD_SIDE;
			sum.v_y += i % BOARD_SIDE;
			count += 1;
		}
	}
	if (count) {
		sum.v_x /= count;
		sum.v_y /= count;
	}
	return (sum);
}

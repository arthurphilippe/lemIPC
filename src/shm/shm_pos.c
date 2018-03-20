/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_pos
*/

#include "lemipc.h"

/*
** Tels if a postion is free to be used.
*/
bool shm_pos_is_free(ipcs_t *ipcs, ivector_t pos)
{
	size_t idx = pos.v_x * (BOARD_SIZE / BOARD_SIDE) + pos.v_y;

	return (pos.v_x >= 0 && pos.v_y >= 0
		&& pos.v_x < BOARD_SIDE && pos.v_y < BOARD_SIDE
		&& ipcs->i_shmsg[idx] == POS_EMPTY);
}

/*
** Returns the group id of the player at the given pos.
*/
int shm_pos_gpid_get(ipcs_t *ipcs, ivector_t pos)
{
	size_t idx = pos.v_x * (BOARD_SIZE / BOARD_SIDE) + pos.v_y;

	if (pos.v_x < 0 || pos.v_y < 0
		|| pos.v_x >= BOARD_SIDE || pos.v_y >= BOARD_SIDE)
		return (0);
	if (!shm_pos_is_free(ipcs, pos) && ipcs->i_shmsg[idx] != POS_EMPTY)
		return (ipcs->i_shmsg[idx] - '0');
	return (0);
}

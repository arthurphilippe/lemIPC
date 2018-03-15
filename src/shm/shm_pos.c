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
	size_t idx = pos.v_y * (BOARD_SIZE / BOARD_SIDE) + pos.v_x;

	return (ipcs->i_shmsg[idx] == POS_EMPTY);
}

/*
** Returns the group id of the player at the given pos.
*/
int shm_pos_gpid_get(ipcs_t *ipcs, ivector_t pos)
{
	size_t idx = pos.v_y * (BOARD_SIZE / BOARD_SIDE) + pos.v_x;

	return (ipcs->i_shmsg[idx] - '0');
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_put
*/

#include "lemipc.h"

void shm_put(ipcs_t *ipcs, ivector_t where, char what)
{
	size_t pos = where.v_x * (BOARD_SIZE / BOARD_SIDE) + where.v_y;

	ipcs->i_shmsg[pos] = what;
}

bool shm_put_try(ipcs_t *ipcs, ivector_t where, char what)
{
	if (shm_pos_is_free(ipcs, where)) {
		shm_put(ipcs, where, what);
		return (true);
	}
	return (false);
}

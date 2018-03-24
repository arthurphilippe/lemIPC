/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_move_to
*/

#include "lemipc.h"

/*
** Tries to move a player directly at the new position.
*/
bool player_move_to(ipcs_t *ipcs, ivector_t *curr, ivector_t new_pos)
{
	if (shm_put_try(ipcs, new_pos, (char) ipcs->i_gpid + '0')) {
		*curr = new_pos;
		return (true);
	}
	return (false);
}

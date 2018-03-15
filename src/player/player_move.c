/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_move
*/

#include <stdio.h>
#include "lemipc.h"

/*
** Tries to move a player closer to the position given as aim.
*/
void player_move_towards(ipcs_t *ipcs, ivector_t *curr, ivector_t aim)
{
	ivector_t new_pos = *curr;

	if (curr->v_x != aim.v_x)
		new_pos.v_x += ((curr->v_x < aim.v_x) ? 1 : -1);
	if (curr->v_y != aim.v_y)
		new_pos.v_y += ((curr->v_y < aim.v_y) ? 1 : -1);
	if (shm_put_try(ipcs, new_pos, (char) ipcs->i_gpid + '0')) {
		shm_put(ipcs, *curr, POS_EMPTY);
		*curr = new_pos;
	}
}

/*
** Tries to move a player directly at the new position.
*/
void player_move_to(ipcs_t *ipcs, ivector_t *curr, ivector_t new_pos)
{
	if (shm_put_try(ipcs, new_pos, (char) ipcs->i_gpid + '0')) {
		shm_put(ipcs, *curr, POS_EMPTY);
		*curr = new_pos;
	}
}

/*
** Tries to move a play in the given direction.
*/
void player_move_by(ipcs_t *ipcs, ivector_t *curr, ivector_t heading)
{
	ivector_t new_pos = {0, 0};

	new_pos.v_x = curr->v_x + heading.v_x;
	new_pos.v_y = curr->v_y + heading.v_y;
	if (shm_put_try(ipcs, new_pos, (char) ipcs->i_gpid + '0')) {
		shm_put(ipcs, *curr, POS_EMPTY);
		*curr = new_pos;
	}
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_ia_2
*/

#include <stdio.h>
#include "lemipc.h"

void player_ia_2_run(ipcs_t *ipcs, ivector_t *pos)
{
	ivector_t barycentre = shm_barycentre_find(ipcs);

	dprintf(1, "\nbary %d, %d\n", barycentre.v_x, barycentre.v_y);
	player_move_fromwards(ipcs, pos, barycentre);
	dprintf(1, "now at %d, %d\n", pos->v_x, pos->v_y);
}

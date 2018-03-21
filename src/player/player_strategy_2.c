/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_strategy_2
*/

#include <stdio.h>
#include "lemipc.h"

void player_strategy_2_run(ipcs_t *ipcs, ivector_t *pos)
{
	ivector_t barycentre = shm_barycentre_find(ipcs);

	player_move_fromwards(ipcs, pos, barycentre);
}

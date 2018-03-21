/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_strategy_1
*/

#include <stdio.h>
#include "lemipc.h"

void player_strategy_1_run(ipcs_t *ipcs, ivector_t *pos)
{
	ivector_t barycentre = shm_barycentre_find(ipcs);

	player_move_towards(ipcs, pos, barycentre);
}

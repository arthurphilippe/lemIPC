/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_play
*/

#include <stdio.h>
#include "lemipc.h"

int lem_play(ipcs_t *ipcs)
{
	ivector_t curr = {0, 0};
	dprintf(1, "[lem_play]\n");
	player_wait_startup(ipcs);
	// player_move_to(ipcs, &curr, (ivector_t) {13, 12});
	dprintf(1, "[/lem_play]\n");
	return (RET_OK);
}

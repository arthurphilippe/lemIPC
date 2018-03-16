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
	(void) ipcs;
	ivector_t curr = {0, 0};
	player_move_to(ipcs, &curr, (ivector_t) {13, 12});
	dprintf(1, "[lem_play]\n");
	return (RET_OK);
}

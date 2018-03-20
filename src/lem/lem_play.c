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
	ivector_t pos;

	sem_value_lock(ipcs->i_sem_set);
	pos = player_find_startpoint(ipcs);
	sem_value_unlock(ipcs->i_sem_set);
	player_wait_startup(ipcs);
	player_loop(ipcs, pos);
	return (RET_OK);
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_loop
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

static void display_winner(ipcs_t *ipcs)
{
	uint i = 0;

	while (ipcs->i_shmsg[i] == POS_EMPTY) {
		i += 1;
	}
	g_print_fcnt("[host] Congratulation on team %c ", ipcs->i_shmsg[i]);
	g_print_fcnt("for their impressive victory!\n");
}

void host_loop(ipcs_t *ipcs)
{
	size_t team_count;

	usleep(ipcs->i_buff_time);
	do {
		sem_value_lock(ipcs->i_sem_set);
		shm_print(ipcs);
		team_count = shm_teams_count(ipcs->i_shmsg);
		if (team_count == 1)
			display_winner(ipcs);
		sem_value_unlock(ipcs->i_sem_set);
		usleep(ipcs->i_buff_time);
	} while (team_count > 1 && !shm_is_stalled(ipcs));
	if (shm_is_stalled(ipcs))
		g_print_fcnt("[host] stoping: stalled for %d cycles\n",
				STALLED_CYCLES_MAX);
}

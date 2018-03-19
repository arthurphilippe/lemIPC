/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_loop
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

void host_loop(ipcs_t *ipcs)
{
	size_t team_count;
	size_t debug_loops = 0;

	usleep(SLEEP_TIME);
	do {
		sem_value_lock(ipcs->i_sem_set);
		shm_print(ipcs);
		team_count = shm_teams_count(ipcs->i_shmsg);
		sem_value_unlock(ipcs->i_sem_set);
		usleep(SLEEP_TIME);
	} while (team_count > 1 && !shm_is_stalled(ipcs));
	if (shm_is_stalled(ipcs))
		dprintf(1, "[host] stoping: stalled for %d cycles\n",
			STALLED_CYCLES_MAX);
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_loop
*/

#include <unistd.h>
#include "lemipc.h"

void host_loop(ipcs_t *ipcs)
{
	size_t team_count;
	usleep(100);
	do {
		sem_value_lock(ipcs->i_sem_set);
		shm_print(ipcs);
		team_count = shm_teams_count(ipcs->i_shmsg);
		sem_value_unlock(ipcs->i_sem_set);
		usleep(100);
	} while (team_count > 1);
}

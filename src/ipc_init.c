/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** ipc_init
*/

#include <stdio.h>
#include <signal.h>
#include "lemipc.h"

int ipc_init_new(ipcs_t *ipcs)
{
	struct sigaction sa;

	sa.sa_handler = ipc_delete_sigint;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (true);
	ipcs->i_shmsg = shm_get_new(ipcs->i_key);
	ipcs->i_msq = msq_get_new(ipcs->i_key);
	ipcs->i_sem_set = sem_suite_get(ipcs->i_key);
	return (ipcs->i_shmsg == NULL
		|| ipcs->i_msq == -1 || ipcs->i_sem_set == -1);
}

int ipc_init_existing(ipcs_t *ipcs)
{
	ipcs->i_shmsg = shm_get_existing(ipcs->i_key);
	ipcs->i_msq = msq_get_existing(ipcs->i_key);
	ipcs->i_sem_set = sem_suite_get(ipcs->i_key);
	return (ipcs->i_shmsg == NULL
		|| ipcs->i_msq == -1 || ipcs->i_sem_set == -1);
}

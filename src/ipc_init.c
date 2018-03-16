/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** ipc_init
*/

#include "lemipc.h"

int ipc_init_new(ipcs_t *ipcs)
{
	ipcs->i_shmsg = shm_get_new(ipcs->i_key);
	ipcs->i_msq = msq_get_new(ipcs->i_key);
	ipcs->i_sem_set = sem_suite_get(ipcs->i_key);
	return (ipcs->i_shmsg == NULL
		|| ipcs->i_msq == -1 || ipcs->i_sem_set == -1);
}

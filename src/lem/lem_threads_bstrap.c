/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_threads_bstrap
*/

#include <stdlib.h>
#include <pthread.h>
#include "lemipc.h"

static void *lem_thread_host(void *ipcs)
{
	lem_host((void *) ipcs);
	return (NULL);
}

static void *lem_thread_play(void *ipcs)
{
	lem_play((void *) ipcs);
	return (NULL);
}

int lem_threads_bstrap(ipcs_t *ipcs)
{
	pthread_t thrds[2];

	if (pthread_create(&thrds[0], NULL, lem_thread_host, ipcs))
		exit(EXT_FAILURE);
	if (pthread_create(&thrds[1], NULL, lem_thread_play, ipcs))
		exit(EXT_FAILURE);
	pthread_join(thrds[0], NULL);
	pthread_join(thrds[1], NULL);
	return (RET_OK);
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_host
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

int lem_host(ipcs_t *ipcs)
{
	size_t player_count;

	usleep(100);
	dprintf(1, "[host] starting...\n");
	player_count = host_wait_startup(ipcs);
	(void) player_count;
	dprintf(1, "[host] started\n");
	shm_print(ipcs);
	dprintf(1, "[host] terminating...\n");
	return (RET_OK);
}

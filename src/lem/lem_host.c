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
	usleep(100);
	dprintf(1, "[lem_host]\n");
	host_wait_startup(ipcs);
	shm_print(ipcs);
	dprintf(1, "[/lem_host]\n");
	return (RET_OK);
}

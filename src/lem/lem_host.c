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
	(void) ipcs;
	usleep(100);
	dprintf(1, "[lem_host]\n");
	shm_print(ipcs);
	return (RET_OK);
}

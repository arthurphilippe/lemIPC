/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_host
*/

#include <stdio.h>
#include "lemipc.h"

int lem_host(ipcs_t *ipcs)
{
	(void) ipcs;
	dprintf(1, "[lem_host]\n");
	shm_print(ipcs);
	return (RET_OK);
}

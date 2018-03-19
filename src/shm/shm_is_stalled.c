/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_is_stalled
*/

#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

bool shm_is_stalled(ipcs_t *ipcs)
{
	static char *buff = NULL;
	static int stalled_cycles_count = 1;

	if (buff == NULL)
		buff = calloc(sizeof(char), BOARD_SIZE);
	if (strcmp(ipcs->i_shmsg, buff) == 0)
		stalled_cycles_count += 1;
	else
		stalled_cycles_count = 0;
	strncpy(buff, ipcs->i_shmsg, BOARD_SIZE);
	return ((stalled_cycles_count >= STALLED_CYCLES_MAX) ? true : false);
}

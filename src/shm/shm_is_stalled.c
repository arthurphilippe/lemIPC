/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_is_stalled
*/

#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

/*
** Checks if the map has been static for STALLED_CYCLES_MAX amount
** of cycles.
*/
bool shm_is_stalled(ipcs_t *ipcs)
{
	static char *buff = NULL;
	static int stalled_cycles_count = 1;

	if (buff == NULL)
		buff = calloc(sizeof(char), BOARD_SIZE);
	if (!ipcs) {
		free(buff);
		buff = NULL;
		return (false);
	}
	if (strncmp(ipcs->i_shmsg, buff, BOARD_SIZE) == 0)
		stalled_cycles_count += 1;
	else
		stalled_cycles_count = 0;
	strncpy(buff, ipcs->i_shmsg, BOARD_SIZE);
	return ((stalled_cycles_count >= STALLED_CYCLES_MAX) ? true : false);
}

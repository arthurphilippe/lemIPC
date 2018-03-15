/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_start
*/

#include "lemipc.h"

int lem_start(const char *path, int team_nb)
{
	ipcs_t ipcs;

	ipcs.i_gpid = team_nb;
	ipcs.i_key = key_get(path);
	if (ipcs.i_key == RET_OK)
		return (RET_ERR);
	ipcs.i_shmsg = shm_get_existing(ipcs.i_key);
	if (ipcs.i_shmsg == NULL) {
		lem_threads_bstrap(&ipcs);
	} else {
		lem_play(&ipcs);
	}
	return (RET_OK);
}

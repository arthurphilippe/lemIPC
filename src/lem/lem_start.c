/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_start
*/

#include <stdlib.h>
#include <string.h>
#include "lemipc.h"

/*
** The key's path is copied into a global varaible so that when a sig int
** is recieved, ipcs data can be freed.
*/
char *g_key_path = NULL;

int lem_start(const char *path, int team_nb)
{
	ipcs_t ipcs;

	ipcs.i_gpid = team_nb;
	ipcs.i_key = key_get(path);
	g_key_path = strdup(path);
	if (ipcs.i_key == RET_OK || !g_key_path || team_nb <= 0)
		return (RET_ERR);
	ipcs.i_shmsg = shm_get_existing(ipcs.i_key);
	if (ipcs.i_shmsg == NULL) {
		if (!ipc_init_new(&ipcs))
			lem_threads_bstrap(&ipcs);
		ipc_delete(path);
	} else {
		if (!ipc_init_existing(&ipcs))
			lem_play(&ipcs);
	}
	free(g_key_path);
	return (RET_OK);
}

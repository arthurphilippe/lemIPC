/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** sem_suite_get
*/

#include <stdio.h>
#include "lemipc.h"

/*
** returns the sem_set id related to a given key
*/
int sem_suite_get(key_t key)
{
	int sem_set_id = semget(key, SEM_NB, IPC_AFLAGS);

	if (sem_set_id == RET_ERR) {
		sem_set_id = semget(key, SEM_NB, IPC_CFLAGS);
		if (sem_set_id == RET_ERR) {
			perror("sem_suite_get");
			return (RET_ERR);
		}
		semctl(sem_set_id, 0, SETVAL, 1);
	}
	return (sem_set_id);
}

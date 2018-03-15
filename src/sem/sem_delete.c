/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** sem_delete
*/

#include "lemipc.h"

void sem_delete(int key)
{
	int sem_set_id = semget(key, SEM_NB, IPC_AFLAGS);

	if (sem_set_id != RET_ERR)
		semctl(sem_set_id, 0, IPC_RMID);
}

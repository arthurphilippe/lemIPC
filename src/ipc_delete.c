/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** ipc_delete
*/

#include "lemipc.h"

void ipc_delete(void)
{
	key_t key = key_get();
	int sem;

	if (key != -1) {
		sem = sem_suite_get(key);
		if (sem != -1)
			sem_delete(sem);
		shm_delete(key);
	}
}

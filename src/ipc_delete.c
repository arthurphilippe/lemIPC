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

	if (key != -1) {
		sem_delete(key);
		shm_delete(key);
		msq_delete(key);
	}
}

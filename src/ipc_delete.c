/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** ipc_delete
*/

#include "lemipc.h"

void ipc_delete(const char *path)
{
	key_t key = key_get(path);

	if (key != -1) {
		sem_delete(key);
		shm_delete(key);
		msq_delete(key);
	}
}

void ipc_delete_test(void)
{
	key_t key = key_get(FTOK_FILE_PATH);

	if (key != -1) {
		sem_delete(key);
		shm_delete(key);
		msq_delete(key);
	}
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_delete
*/

#include "lemipc.h"

void shm_delete_from_scratch(void)
{
	key_t key = key_get();
	int shm_id = shmget(key, BOARD_SIZE, IPC_AFLAGS);

	if (shm_id != -1)
		shm_delete(shm_id);
}

void shm_delete(int shm_id)
{
	shmctl(shm_id, IPC_RMID, NULL);
}

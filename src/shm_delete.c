/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_delete
*/

#include "lemipc.h"

void shm_delete(key_t key)
{
	int shm_id = shmget(key, BOARD_SIZE, IPC_AFLAGS);

	if (shm_id != -1)
		shmctl(shm_id, IPC_RMID, NULL);
}

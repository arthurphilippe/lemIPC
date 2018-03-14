/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_get
*/

#include <stdio.h>
#include "lemipc.h"

void *shm_get_existing(key_t key)
{
	int shm_id = shmget(key, BOARD_SIZE, IPC_AFLAGS);

	if (shm_id == -1) {
		perror("shm");
		return (NULL);
	}
	return (shmat(shm_id, NULL, IPC_AFLAGS));
}

void *shm_get_new(key_t key)
{
	int shm_id = shmget(key, BOARD_SIZE, IPC_AFLAGS);

	if (shm_id == -1)
		shm_id = shmget(key, BOARD_SIZE, IPC_CFLAGS);
	if (shm_id == -1) {
		perror("shm");
		return (NULL);
	}
	return (shmat(shm_id, NULL, IPC_AFLAGS));
}

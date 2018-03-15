/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msq_get
*/

#include "lemipc.h"

int msq_get_new(key_t key)
{
	int msq_id = msgget(key, IPC_AFLAGS);

	if (msq_id == -1)
		msq_id = msgget(key, IPC_CFLAGS);
	return (msq_id);
}

int msq_get_existing(key_t key)
{
	return (msgget(key, IPC_AFLAGS));
}

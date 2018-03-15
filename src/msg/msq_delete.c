/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msq_delete
*/

#include "lemipc.h"

void msq_delete(key_t key)
{
	int msq_id = msgget(key, IPC_AFLAGS);

	if (msq_id != -1)
		msgctl(msq_id, IPC_RMID, NULL);
}

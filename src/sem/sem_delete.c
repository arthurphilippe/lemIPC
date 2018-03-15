/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** sem_delete
*/

#include "lemipc.h"

void sem_delete(int sem_suite_id)
{
	semctl(sem_suite_id, 0, IPC_RMID);
}

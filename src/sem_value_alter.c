/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** sem_value_alter
*/

#include "lemipc.h"

void sem_value_sub(int sem_id)
{
	sem_value_alter(sem_id, -1);
}

void sem_value_add(int sem_id)
{
	sem_value_alter(sem_id, 1);
}

void sem_value_alter(int sem_id, int value)
{
	struct sembuf add;

	add.sem_num = 0;
	add.sem_flg = 0;
	add.sem_op = value;
	semop(sem_id, &add, 1);
}

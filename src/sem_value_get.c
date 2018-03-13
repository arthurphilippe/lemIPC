/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** sem_value_get
*/

#include "lemipc.h"

int sem_value_get(int semId)
{
	return (semctl(semId, 0, GETVAL));
}

/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_print
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

void shm_print(ipcs_t *ipcs)
{
	display_select(ipcs, false);
}

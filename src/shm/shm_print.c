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
	size_t line = 0;
	size_t line_idx;

	dprintf(1, "\033[1m\033[33m~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\033[0m");
	while (line < BOARD_SIDE) {
		line_idx = line * (BOARD_SIZE / BOARD_SIDE);
		write(STDOUT_FILENO, &ipcs->i_shmsg[line_idx], BOARD_SIDE);
		write(STDOUT_FILENO, "\n", 1);
		line += 1;
	}
}

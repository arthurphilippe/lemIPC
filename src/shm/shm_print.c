/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_print
*/

#include <unistd.h>
#include "lemipc.h"

void shm_print(ipcs_t *ipcs)
{
	size_t line = 0;
	size_t line_idx;

	while (line < BOARD_SIDE) {
		line_idx = line * (BOARD_SIZE / BOARD_SIDE);
		write(STDOUT_FILENO, &ipcs->i_shmsg[line_idx], BOARD_SIDE);
		write(STDOUT_FILENO, "\n", 1);
		line += 1;
	}
}

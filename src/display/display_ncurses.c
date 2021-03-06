/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** display_ncurses
*/

#include <ncurses.h>
#include <curses.h>
#include "lemipc.h"

void display_ncurses(ipcs_t *ipcs)
{
	size_t line = 0;
	size_t line_idx;

	curs_set(0);
	clear();
	while (line < BOARD_SIDE) {
		line_idx = line * (BOARD_SIZE / BOARD_SIDE);
		printw("%.20s\n", &ipcs->i_shmsg[line_idx], BOARD_SIDE);
		line += 1;
	}
	if (!ipcs->i_curr_cycle) {
		printw("[host] waiting for connections...\n");
	}
	else
		printw("\ncurrent cycle: %d.\n", ipcs->i_curr_cycle);
	refresh();
}

void display_ncurses_init(void)
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, 1);
}

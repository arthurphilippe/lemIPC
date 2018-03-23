/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** display_select
*/

#include <ncurses.h>
#include <curses.h>
#include "lemipc.h"

int (*g_print_fcnt)(const char *format, ...) = printf;

void display_select(ipcs_t *ipcs, bool mod)
{
	static bool ncurses_selected = false;

	if (!ipcs && mod) {
		ncurses_selected = mod;
		display_ncurses_init();
		g_print_fcnt = printw;
	}
	else if (!ncurses_selected)
		display_basic(ipcs);
	else
		display_ncurses(ipcs);
}

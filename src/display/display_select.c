/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** display_select
*/

#include "lemipc.h"

void display_select(ipcs_t *ipcs, bool mod)
{
	static bool ncurses_selected = false;

	if (!ipcs) {
		ncurses_selected = mod;
		display_ncurses_init();
	}
	else if (!ncurses_selected)
		display_basic(ipcs);
	else
		display_ncurses(ipcs);
}

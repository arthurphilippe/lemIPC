/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** main
*/

#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

static void print_usage(void)
{
	FILE *fd = fopen("helper.txt", "r");
	int length;
	char str[1024];

	if ((fseek(fd, 0, SEEK_END)) == RET_ERR)
		return;
	length = ftell(fd);
	if (length == RET_ERR)
		return;
	if ((fseek(fd, 0, SEEK_SET)) == RET_ERR)
		return;
	memset(str, '\0', 1024);
	fread(str, length, 1, fd);
	fclose(fd);
	printf("%s", str);
}

static void lem_opt_fix_buff(int *buff_time)
{
	if (*buff_time <= 0)
		*buff_time = SLEEP_TIME;
	else if (*buff_time < 100)
		*buff_time = 100;
}

static lem_opt_t lem_opt_get(int ac, char **av)
{
	lem_opt_t opt;
	int i = 3;

	memset(&opt, 0, sizeof(lem_opt_t));
	while (i < ac) {
		if (!strcasecmp(av[i], "ncurses")) {
			opt.ncurses = true;
			display_select(NULL, true);
		} else if (av[i][0] >= '0' && av[i][0] <= '9') {
			opt.buff_time = atoi(av[i]) * 1000;
		} else {
			dprintf(2, "%s: unknown argument: %s\n", av[0], av[i]);
		}
		i += 1;
	}
	lem_opt_fix_buff(&opt.buff_time);
	return (opt);
}

int main(int ac, char **av)
{
	lem_opt_t opt;
	int ret = RET_ERR;

	if (ac >= 3) {
		opt = lem_opt_get(ac, av);
		ret = lem_start(av[1], atoi(av[2]), opt.buff_time);
		if (opt.ncurses) {
			printw("Press any key to quit...\n");
			refresh();
			timeout(5000);
			getch();
			endwin();
		}
	} else
		print_usage();
	return (ret == RET_ERR ? EXT_FAILURE : EXT_SUCCESS);
}

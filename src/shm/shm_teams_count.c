/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** shm_teams_count
*/

#include <string.h>
#include "lemipc.h"

static bool team_was_found(char *shmsg, uint team_found[], size_t i)
{
	if (shmsg[i] == '.')
		return (true);
	for (size_t j = 0; j < 10; j += 1) {
		if (team_found[j] == (uint) (shmsg[i] - '0'))
			return (true);
	}
	return (false);
}

static void append_new_found_team(uint team, uint team_found[])
{
	for (size_t i = 0; i < 10; i += 1) {
		if (!team_found[i]) {
			team_found[i] = team;
			return;
		}
	}
}

static size_t get_found_nb(uint team_found[])
{
	size_t i = 0;

	while (i < 10 && team_found[i])
		i += 1;
	return (i);
}

size_t shm_teams_count(char *shmsg)
{
	uint team_found[10];

	memset(&team_found, 0, sizeof(uint) * 10);
	for (size_t i = 0; i < BOARD_SIZE; i += 1) {
		if (!team_was_found(shmsg, team_found, i))
			append_new_found_team((shmsg[i] - '0'), team_found);
	}
	return (get_found_nb(team_found));
}

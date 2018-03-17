/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_wait
*/

#include <stdio.h>
#include "lemipc.h"

size_t host_wait_startup(ipcs_t *ipcs)
{
	bool is_game_ready = false;
	int first_gpid = -1;
	payld_t data;
	size_t total_players = 0;

	printf("[host] waiting for players...\n");
	while (!is_game_ready) {
		data = msg_collect(ipcs->i_msq, MSG_CH_HOST, 0);
		if (first_gpid == -1) {
			first_gpid = data.p_b;
		} else if (data.p_b != first_gpid) {
			is_game_ready = true;
		}
		total_players += 1;
	}
	// while (shm_teams_count(ipcs->i_shmsg) <= 1);
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {MSG_CYCLE, 0, 0});
	printf("[host] %ld players connected. Ready.\n", total_players);
	return (total_players);
}

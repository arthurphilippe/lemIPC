/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_wait
*/

#include "lemipc.h"

size_t host_wait_startup(ipcs_t *ipcs)
{
	bool is_game_ready = false;
	int first_gpid = -1;
	payld_t data;
	size_t total_players;

	while (!is_game_ready) {
		data = msg_collect(ipcs->i_msq, MSG_CH_HOST, 0);
		if (first_gpid == -1) {
			first_gpid = data.d_b;
		} else if (data.d_b != first_gpid) {
			is_game_ready = true;
		}
		total_players += 1;
	}
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {0, 0, 0});
	return (total_players);
}

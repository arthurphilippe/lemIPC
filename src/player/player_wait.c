/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_wait
*/

#include "lemipc.h"

void player_wait_startup(ipcs_t *ipcs)
{
	payld_t msg;
	bool start = false;
	bool time_rcvd = false;
	msg_send(ipcs->i_msq, MSG_CH_HOST,
			(payld_t) {MSG_PLAYER_NEW, ipcs->i_gpid, 0});
	do {
		msg = msg_collect_repeat(ipcs->i_msq, MSG_CH_BRD, 0);
		if (msg.p_a == MSG_BUFF) {
			ipcs->i_buff_time = msg.p_b;
			time_rcvd = true;
		}
		if (msg.p_a == MSG_CYCLE)
			start = true;
	} while (!start || !time_rcvd);
}

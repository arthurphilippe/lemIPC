/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_wait
*/

#include "lemipc.h"

void player_wait_startup(ipcs_t *ipcs)
{
	msg_send(ipcs->i_msq, MSG_CH_HOST,
			(payld_t) {MSG_PLAYER_NEW, ipcs->i_gpid, 0});
	msg_send(ipcs->i_msq, MSG_CH_HOST,
			(payld_t) {MSG_PLAYER_NEW, ipcs->i_gpid + 1, 0});
	msg_collect(ipcs->i_msq, MSG_CH_BRD, 0);
}

void player_wait(ipcs_t *ipcs)
{
	msg_collect(ipcs->i_msq, MSG_CH_BRD, 0);
}

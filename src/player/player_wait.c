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
	msg_collect_repeat(ipcs->i_msq, MSG_CH_BRD, 0);
}

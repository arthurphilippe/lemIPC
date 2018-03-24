/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lem_host
*/

#include <stdio.h>
#include <unistd.h>
#include "lemipc.h"

int lem_host(ipcs_t *ipcs)
{
	usleep(ipcs->i_buff_time);
	msg_send(ipcs->i_msq, MSG_CH_BRD,
			(payld_t) {MSG_BUFF, ipcs->i_buff_time, 0});
	ipcs->i_curr_cycle = 0;
	host_wait_startup(ipcs);
	ipcs->i_curr_cycle += 1;
	host_loop(ipcs);
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {MSG_END, 0, 0});
	return (RET_OK);
}

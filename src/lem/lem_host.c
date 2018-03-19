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
	usleep(SLEEP_TIME);
	dprintf(1, "[host] starting...\n");
	host_wait_startup(ipcs);
	dprintf(1, "[host] started\n");
	host_loop(ipcs);
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {MSG_END, 0, 0});
	usleep(1000000);
	dprintf(1, "[host] terminating...\n");
	return (RET_OK);
}

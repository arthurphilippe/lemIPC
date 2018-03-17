/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** host_terminate
*/

#include "lemipc.h"

void host_terminate(ipcs_t *ipcs)
{
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {MSG_END, 0, 0});
}

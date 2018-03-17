/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg_send
*/

#include <stdio.h>
#include "lemipc.h"

void msg_send(int msq_id, long channel, payld_t payload)
{
	msg_t	msg;

	msg.m_channel = channel;
	msg.m_data = payload;
	msgsnd(msq_id, &msg, sizeof(payld_t), 0);
	dprintf(1, "message sent to %ld\n", channel);
}

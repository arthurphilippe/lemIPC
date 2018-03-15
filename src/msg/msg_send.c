/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg_send
*/

#include "lemipc.h"

void msg_send(int msq_id, long channel, int code)
{
	msg_t	msg;

	msg.m_channel = channel;
	msg.m_data.d_a = code;
	msgsnd(msq_id, &msg, sizeof(msg), 0);
}
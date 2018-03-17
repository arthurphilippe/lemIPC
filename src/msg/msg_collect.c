/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg_collect
*/

#include <string.h>
#include "lemipc.h"

payld_t msg_collect(int msq_id, long channel, int flags)
{
	msg_t msg;

	memset(&msg, 0, sizeof(msg_t));
	msgrcv(msq_id, &msg, sizeof(msg), channel, flags);
	return (msg.m_data);
}

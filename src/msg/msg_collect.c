/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg_collect
*/

#include "lemipc.h"

payld_t msg_collect(int msq_id, long channel, int flags)
{
	msg_t msg;

	msgrcv(msq_id, &msg, sizeof(msg), channel, flags);
	return (msg.m_data);
}

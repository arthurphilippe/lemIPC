/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** msg_collect
*/

#include "lemipc.h"

msg_t msg_collect(int msq_id, long channel)
{
	msg_t msg;

	msgrcv(msq_id, &msg, sizeof(msg), channel, 0);
	return (msg);
}

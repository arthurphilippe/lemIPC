/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_loop
*/

#include <stdio.h>
#include <errno.h>
#include "lemipc.h"

void player_loop(ipcs_t *ipcs, ivector_t pos)
{
	payld_t msg;

	do {
		// sem_value_lock(ipcs->i_sem_set);
		// player_move_towards(ipcs, &pos, (ivector_t) {10, 10});
		// sem_value_unlock(ipcs->i_sem_set);
		errno = 0;
		msg = msg_collect(ipcs->i_msq, MSG_CH_BRD, IPC_NOWAIT);
		usleep(100);
	} while (msg.p_a != MSG_END);
	msg_send(ipcs->i_msq, MSG_CH_BRD, (payld_t) {MSG_END, 0, 0});
	// } while (msg.p_a != MSG_END);
}

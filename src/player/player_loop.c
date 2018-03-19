/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_loop
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "lemipc.h"

void player_loop(ipcs_t *ipcs, ivector_t pos)
{
	payld_t msg;

	do {
		errno = 0;
		sem_value_lock(ipcs->i_sem_set);
		if (errno != 0 && errno != ENOMSG)
			break;
		player_move_towards(ipcs, &pos, (ivector_t) {10, 10});
		sem_value_unlock(ipcs->i_sem_set);
		errno = 0;
		msg = msg_collect_repeat(ipcs->i_msq, MSG_CH_BRD, IPC_NOWAIT);
		usleep(SLEEP_TIME);
	} while (msg.p_a != MSG_END && player_is_killed(ipcs, pos) == false
			&& (errno == 0 || errno == ENOMSG));
	shm_put(ipcs, pos, POS_EMPTY);
}

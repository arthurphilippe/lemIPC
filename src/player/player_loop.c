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

void (*const IA_FNCTS[]) (ipcs_t *, ivector_t *) = {
	player_strategy_1_run,
	player_strategy_2_run,
	player_strategy_3_run,
	NULL,
};

static void player_strategy_select(ipcs_t *ipcs, ivector_t *pos)
{
	int selected = (ipcs->i_gpid - 1) % (IMPLEMENTED_STATEGIES);

	if (selected == 1 && ipcs->i_curr_cycle > (MAX_CYCLES / 4)) {
		IA_FNCTS[2](ipcs, pos);
	}
	else
		IA_FNCTS[selected](ipcs, pos);
}

void player_loop(ipcs_t *ipcs, ivector_t pos)
{
	payld_t msg;
	bool is_killed;

	ipcs->i_curr_cycle = 1;
	do {
		errno = 0;
		sem_value_lock(ipcs->i_sem_set);
		if (errno != 0 && errno != ENOMSG)
			break;
		is_killed = player_is_killed(ipcs, pos);
		player_strategy_select(ipcs, &pos);
		sem_value_unlock(ipcs->i_sem_set);
		errno = 0;
		msg = msg_collect_repeat(ipcs->i_msq, MSG_CH_BRD, IPC_NOWAIT);
		usleep(ipcs->i_buff_time);
		ipcs->i_curr_cycle += 1;
	} while (msg.p_a != MSG_END && is_killed == false
			&& (errno == 0 || errno == ENOMSG));
	shm_put(ipcs, pos, POS_EMPTY);
}

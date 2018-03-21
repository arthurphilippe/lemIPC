/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_strategy_3
*/

#include <errno.h>
#include "lemipc.h"

void player_strategy_3_run(ipcs_t *ipcs, ivector_t *pos)
{
	payld_t msg;
	ivector_t tgt;

	errno = 0;
	msg = msg_collect(ipcs->i_msq, MSG_CH_BASE + ipcs->i_gpid,
				IPC_NOWAIT);
	if (errno == ENOMSG) {
		tgt = shm_foe_find(ipcs, *pos);
	} else {
		tgt.v_x = msg.p_a;
		tgt.v_y = msg.p_b;
		if (shm_pos_gpid_get(ipcs, tgt) == 0
			|| shm_pos_gpid_get(ipcs, tgt) == ipcs->i_gpid)
			tgt = shm_foe_find(ipcs, *pos);
	}
	msg_send(ipcs->i_msq, MSG_CH_BASE + ipcs->i_gpid,
			(payld_t) {tgt.v_x, tgt.v_y, 0});
	player_move_towards(ipcs, pos, tgt);
}

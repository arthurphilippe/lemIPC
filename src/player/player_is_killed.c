/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** player_is_killed
*/

#include "lemipc.h"

static bool vec_is_out_of_bound(ivector_t pos, ivector_t mod)
{
	return (mod.v_x > 1 || (pos.v_x + mod.v_x) >= BOARD_SIDE);
}

static ivector_t mod_apl(ivector_t pos, ivector_t mod)
{
	return ((ivector_t) {pos.v_x + mod.v_x, pos.v_y + mod.v_y});
}

bool player_is_killed(ipcs_t *ipcs, ivector_t pos)
{
	ivector_t mod = {-1, -1};
	uint foe_count = 0;
	int foe_team;

	while (!vec_is_out_of_bound(pos, mod)) {
		foe_team = shm_pos_gpid_get(ipcs, mod_apl(pos, mod));
		if (foe_team != 0 && foe_team != ipcs->i_gpid)
			foe_count += 1;
		if (mod.v_y == 1)
			mod.v_x += 1;
		mod.v_y = (mod.v_y == 1) ? -1 : mod.v_y + 1;
	}
	return (foe_count >= 2);
}

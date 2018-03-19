/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_player
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(player, put, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;
	ivector_t pos = {0, 0};

	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipcs.i_shmsg = shm_get_new(ipcs.i_key);
	ipcs.i_gpid = 4;

	player_move_to(&ipcs, &pos, (ivector_t) {3, 3});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 3}), 4);
	player_move_to(&ipcs, &pos, (ivector_t) {3, 3});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 3}), 4);
}

Test(player, move_by, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;
	ivector_t pos = {0, 0};

	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipcs.i_shmsg = shm_get_new(ipcs.i_key);
	ipcs.i_gpid = 4;

	player_move_to(&ipcs, &pos, (ivector_t) {3, 3});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 3}), 4);
	player_move_by(&ipcs, &pos, (ivector_t) {1, -1});
	cr_assert_eq(shm_pos_is_free(&ipcs, (ivector_t) {3, 3}), true);
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {4, 2}), 4);
	cr_assert_eq(shm_pos_gpid_get(&ipcs, pos), 4);
	player_move_by(&ipcs, &pos, (ivector_t) {0, 0});
	cr_assert_eq(shm_pos_is_free(&ipcs, (ivector_t) {3, 3}), true);
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {4, 2}), 4);
	cr_assert_eq(shm_pos_gpid_get(&ipcs, pos), 4);
}

Test(player, move_toward, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;
	ivector_t pos = {0, 0};

	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipcs.i_shmsg = shm_get_new(ipcs.i_key);
	ipcs.i_gpid = 7;

	player_move_to(&ipcs, &pos, (ivector_t) {3, 3});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 3}), 7);
	player_move_towards(&ipcs, &pos, (ivector_t) {0, 0});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {2, 2}), 7);
	player_move_towards(&ipcs, &pos, (ivector_t) {3, 1});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 1}), 7);
	player_move_towards(&ipcs, &pos, (ivector_t) {3, 1});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 1}), 7);
	player_move_towards(&ipcs, &pos, (ivector_t) {3, 3});
	cr_assert_eq(shm_pos_gpid_get(&ipcs, (ivector_t) {3, 2}), 7);
}

Test(player, place, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);

	ipc_init_new(&ipcs);
	player_find_startpoint(&ipcs);
	ipcs.i_gpid = 2;
	player_find_startpoint(&ipcs);
	ipcs.i_gpid = 3;
	player_find_startpoint(&ipcs);
	ipcs.i_gpid = 4;
	player_find_startpoint(&ipcs);
}

Test(player, kill1, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;
	ivector_t pos;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipc_init_new(&ipcs);

	player_move_to(&ipcs, &pos, (ivector_t) {14, 12});
	ipcs.i_gpid = 2;
	player_move_to(&ipcs, &pos, (ivector_t) {13, 12});
	player_move_to(&ipcs, &pos, (ivector_t) {13, 11});
	pos.v_x = 14;
	pos.v_y = 12;
	ipcs.i_gpid = 1;
	cr_assert_eq(player_is_killed(&ipcs, pos), true);
}

Test(player, kill2fail, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;
	ivector_t pos;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipc_init_new(&ipcs);

	player_move_to(&ipcs, &pos, (ivector_t) {14, 12});
	ipcs.i_gpid = 2;
	// player_move_to(&ipcs, &pos, (ivector_t) {13, 12});
	player_move_to(&ipcs, &pos, (ivector_t) {13, 11});
	pos.v_x = 14;
	pos.v_y = 12;
	ipcs.i_gpid = 1;
	cr_assert_eq(player_is_killed(&ipcs, pos), false);
}

Test(player, wait) {
	ipcs_t ipcs;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipc_init_new(&ipcs);

	msg_send(ipcs.i_msq, MSG_CH_BRD, (payld_t) {MSG_CYCLE, 0, 0});
	player_wait_startup(&ipcs);
	cr_assert(true);
}

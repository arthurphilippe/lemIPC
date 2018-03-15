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

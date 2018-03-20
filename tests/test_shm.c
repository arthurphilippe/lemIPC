/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_shm
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lemipc.h"

Test(shm, basic, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	char *addr = shm_get_new(key);

	strcpy(addr, "salut");
	cr_assert_str_eq(addr, "salut");
	shmdt(addr);
	addr = shm_get_existing(key);
	cr_assert_str_eq(addr, "salut");
}

Test(shm, double_new, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	char *addr = shm_get_new(key);

	addr = shm_get_new(key);
	strcpy(addr, "salut");
	cr_assert_str_eq(addr, "salut");
	shmdt(addr);
	addr = shm_get_existing(key);
	cr_assert_str_eq(addr, "salut");
}

Test(shm, failingSize, .init = ipc_delete_test, .fini = ipc_delete_test) {
	cr_redirect_stderr();
	cr_redirect_stdout();
	key_t key = key_get(FTOK_FILE_PATH);
	int shm_id = shmget(key, 10, IPC_CFLAGS);
	char *addr = shm_get_new(key);

	cr_expect_eq(addr, NULL);
	shmctl(shm_id, IPC_RMID, NULL);
}

Test(shm, failingUnexisting, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	char *addr = shm_get_existing(key);

	cr_expect_eq(addr, NULL);
}

Test(shm, teams_count) {
	char *shmsg = malloc(BOARD_SIZE);

	if (!shmsg)
		cr_assert_fail("malloc error");
	memset(shmsg, '.', BOARD_SIZE);
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 0);
	shmsg[23] = '1';
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 1);
	shmsg[32] = '3';
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 2);
	shmsg[27] = '2';
	shmsg[78] = '1';
	shmsg[276] = '3';
	shmsg[321] = '3';
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 3);
	shmsg[322] = '4';
	shmsg[323] = '5';
	shmsg[324] = '6';
	shmsg[325] = '7';
	shmsg[326] = '8';
	shmsg[327] = '9';
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 9);
	shmsg[328] = 10 + '0';
	shmsg[328] = 11 + '0';
	cr_assert_eq(shm_teams_count(shmsg), (size_t) 10);
}

Test(shm, is_stalled) {
	ipcs_t ipcs;

	ipcs.i_shmsg = malloc(BOARD_SIZE);
	if (!ipcs.i_shmsg)
		cr_assert_fail("malloc error");
	memset(ipcs.i_shmsg, '.', BOARD_SIZE);

	for (uint i = 0; i <= STALLED_CYCLES_MAX; i += 1) {
		shm_is_stalled(&ipcs);
	}
	cr_assert(shm_is_stalled(&ipcs));
	ipcs.i_shmsg[42] = '1';
	cr_assert_not(shm_is_stalled(&ipcs));
	for (uint i = 0; i <= STALLED_CYCLES_MAX; i += 1) {
		shm_is_stalled(&ipcs);
	}
	cr_assert(shm_is_stalled(&ipcs));
}

Test(shm, barycentre_find) {
	ipcs_t ipcs;
	ivector_t res;

	ipcs.i_shmsg = malloc(BOARD_SIZE);
	ipcs.i_gpid = 4;
	if (!ipcs.i_shmsg)
		cr_assert_fail("malloc error");
	memset(ipcs.i_shmsg, '.', BOARD_SIZE);

	res = shm_barycentre_find(&ipcs);
	cr_assert(res.v_x == 0);
	cr_assert(res.v_y == 0);
	ipcs.i_shmsg[42] = '1';
	res = shm_barycentre_find(&ipcs);
	cr_assert(res.v_x == 2);
	cr_assert(res.v_y == 2);
	ipcs.i_shmsg[245] = '7';
	res = shm_barycentre_find(&ipcs);
	cr_assert(res.v_x == 7);
	cr_assert(res.v_y == 3);
	ipcs.i_shmsg[88] = '5';
	res = shm_barycentre_find(&ipcs);
	cr_assert(res.v_x == 6);
	cr_assert(res.v_y == 5);
	ipcs.i_shmsg[288] = '4';
	res = shm_barycentre_find(&ipcs);
	cr_assert(res.v_x == 6);
	cr_assert(res.v_y == 5);
}

Test(shm, barycentre_find_target) {
	ipcs_t ipcs;
	ivector_t res;

	ipcs.i_shmsg = malloc(BOARD_SIZE);
	ipcs.i_gpid = 4;
	if (!ipcs.i_shmsg)
		cr_assert_fail("malloc error");
	memset(ipcs.i_shmsg, '.', BOARD_SIZE);

	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 0);
	cr_assert(res.v_y == 0);
	ipcs.i_shmsg[42] = '9';
	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 2);
	cr_assert(res.v_y == 2);
	ipcs.i_shmsg[345] = '8';
	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 2);
	cr_assert(res.v_y == 2);
	ipcs.i_shmsg[245] = '9';
	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 7);
	cr_assert(res.v_y == 3);
	ipcs.i_shmsg[88] = '9';
	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 6);
	cr_assert(res.v_y == 5);
	ipcs.i_shmsg[288] = '3';
	res = shm_barycentre_find_target(&ipcs, 9);
	cr_assert(res.v_x == 6);
	cr_assert(res.v_y == 5);
}


/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_shm
*/

#include <criterion/criterion.h>
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

Test(shm, team_count) {
	char *shmsg = malloc(400);

	if (!shmsg)
		cr_assert_fail("malloc error");
	memset(shmsg, '.', 400);
	cr_assert_eq(shm_team_count(shmsg), (size_t) 0);
	shmsg[23] = '1';
	cr_assert_eq(shm_team_count(shmsg), (size_t) 1);
	shmsg[32] = '3';
	cr_assert_eq(shm_team_count(shmsg), (size_t) 2);
	shmsg[27] = '2';
	shmsg[78] = '1';
	shmsg[276] = '3';
	shmsg[321] = '3';
	cr_assert_eq(shm_team_count(shmsg), (size_t) 3);
}

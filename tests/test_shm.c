/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_shm
*/

#include "criterion/criterion.h"
#include "lemipc.h"

Test(shm, basic, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	char *addr = shm_get_new(key);

	strcpy(addr, "salut");
	cr_assert_str_eq(addr, "salut");
	shmdt(addr);
	addr = shm_get_existing(key);
	cr_assert_str_eq(addr, "salut");
}

Test(shm, double_new, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	char *addr = shm_get_new(key);

	addr = shm_get_new(key);
	strcpy(addr, "salut");
	cr_assert_str_eq(addr, "salut");
	shmdt(addr);
	addr = shm_get_existing(key);
	cr_assert_str_eq(addr, "salut");
}

Test(shm, failingSize, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	int shm_id = shmget(key, 10, IPC_CFLAGS);
	char *addr = shm_get_new(key);

	cr_expect_eq(addr, NULL);
	shmctl(shm_id, IPC_RMID, NULL);
}

Test(shm, failingUnexisting, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	char *addr = shm_get_existing(key);

	cr_expect_eq(addr, NULL);
}

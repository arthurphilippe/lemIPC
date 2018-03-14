/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_sem
*/

#include "criterion/criterion.h"
#include "lemipc.h"

Test(sem, basic, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	int sem = sem_suite_get(key);

	cr_assert((sem_value_get(sem) == 1));
	sem_value_sub(sem);
	cr_assert((sem_value_get(sem) == 0));
	sem_value_add(sem);
	sem_value_sub(sem);
	sem_value_add(sem);
	sem_value_add(sem);
	sem_value_add(sem);
	cr_assert((sem_value_get(sem) == 3));
}

Test(shm, basic, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	char *addr = shm_get(key);

	strcpy(addr, "salut");
	cr_assert_str_eq(addr, "salut");
	shmdt(addr);
	addr = shm_get(key);
	cr_assert_str_eq(addr, "salut");
}

Test(shm, failing, .init = ipc_delete, .fini = ipc_delete) {
	key_t key = key_get();
	int shm_id = shmget(key, 10, IPC_CFLAGS);
	char *addr = shm_get(key);

	cr_expect_eq(addr, NULL);
	shmctl(shm_id, IPC_RMID, NULL);
}

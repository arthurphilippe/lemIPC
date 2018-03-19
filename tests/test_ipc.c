/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_ipc
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(ipc, init, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);

	ipc_init_new(&ipcs);
	cr_assert_neq(ipcs.i_key, -1);
	cr_assert_neq(ipcs.i_msq, -1);
	cr_assert_neq(ipcs.i_sem_set, -1);
	cr_assert_neq(ipcs.i_shmsg, NULL);
	sem_value_lock(ipcs.i_sem_set);
	player_find_startpoint(&ipcs);
	sem_value_unlock(ipcs.i_sem_set);
	memset(&ipcs, 0, sizeof(ipcs_t));
}

Test(ipc, init_existing, .init = ipc_delete_test, .fini = ipc_delete_test) {
	ipcs_t ipcs;

	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipc_init_new(&ipcs);
	cr_assert_neq(ipcs.i_key, -1);
	cr_assert_neq(ipcs.i_msq, -1);
	cr_assert_neq(ipcs.i_sem_set, -1);
	cr_assert_neq(ipcs.i_shmsg, NULL);
	sem_value_lock(ipcs.i_sem_set);
	player_find_startpoint(&ipcs);
	sem_value_unlock(ipcs.i_sem_set);
	memset(&ipcs, 0, sizeof(ipcs_t));
	ipcs.i_gpid = 1;
	ipcs.i_key = key_get(FTOK_FILE_PATH);
	ipc_init_existing(&ipcs);
	cr_assert_neq(ipcs.i_key, -1);
	cr_assert_neq(ipcs.i_msq, -1);
	cr_assert_neq(ipcs.i_sem_set, -1);
	cr_assert_neq(ipcs.i_shmsg, NULL);
}

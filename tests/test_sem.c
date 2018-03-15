/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_sem
*/

#include "criterion/criterion.h"
#include "lemipc.h"

Test(sem, basic, .init = ipc_delete_test, .fini = ipc_delete_test) {
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

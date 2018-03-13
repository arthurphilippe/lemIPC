/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_sem
*/

#include "criterion/criterion.h"
#include "lemipc.h"

Test(basic, sem) {
	key_t key = key_get();
	int sem = sem_suite_get(key);

	sem_delete(sem);

	sem = sem_suite_get(key);
	shm_delete_from_scratch();
	cr_assert((sem_value_get(sem) == 1));
	sem_value_sub(sem);
	cr_assert((sem_value_get(sem) == 0));
}

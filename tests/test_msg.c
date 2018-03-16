/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_msg
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(msg, basic, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	int msq_id = msq_get_new(key);

	msq_id = msq_get_new(key);
	msg_send(msq_id, 1, (payld_t) {42, 0, 0});
	payld_t msg = msg_collect(msq_id, 1, 0);
	cr_assert_eq(msg.d_a, 42);
	msg_send(msq_id, 1, (payld_t) {37, 0, 0});
	msg_send(msq_id, 1, (payld_t) {99, 0, 0});
	msg = msg_collect(msq_id, 1, 0);
	cr_assert_eq(msg.d_a, 37);
	msq_id = msq_get_existing(key);
	msg = msg_collect(msq_id, 1, 0);
	cr_assert_eq(msg.d_a, 99);
}

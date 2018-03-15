/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** test_msg
*/

#include "criterion/criterion.h"
#include "lemipc.h"

Test(msg, basic, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	int msq_id = msq_get_new(key);

	msq_id = msq_get_new(key);
	msg_send(msq_id, 1, 42);
	msg_t msg = msg_collect(msq_id, 1);
	cr_assert_eq(msg.m_data.d_a, 42);
	msg_send(msq_id, 1, 37);
	msg_send(msq_id, 1, 99);
	msg = msg_collect(msq_id, 1);
	cr_assert_eq(msg.m_data.d_a, 37);
	msq_id = msq_get_existing(key);
	msg = msg_collect(msq_id, 1);
	cr_assert_eq(msg.m_data.d_a, 99);
}

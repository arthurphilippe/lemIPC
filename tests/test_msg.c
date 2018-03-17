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
	payld_t msg = msg_collect(msq_id, 1, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 42);
	msg_send(msq_id, 1, (payld_t) {37, 0, 0});
	msg_send(msq_id, 1, (payld_t) {99, 0, 0});
	msg = msg_collect(msq_id, 1, 0);
	cr_assert_eq(msg.p_a, 37);
	msq_id = msq_get_existing(key);
	msg = msg_collect(msq_id, 1, 0);
	cr_assert_eq(msg.p_a, 99);
}

Test(msg, chanel, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	int msq_id = msq_get_new(key);

	msq_id = msq_get_new(key);
	msg_send(msq_id, 6, (payld_t) {42, 0, 0});
	payld_t msg = msg_collect(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 42);
	msg_send(msq_id, 6, (payld_t) {37, 0, 0});
	msg_send(msq_id, 6, (payld_t) {99, 0, 0});
	msg = msg_collect_repeat(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 37);
	msq_id = msq_get_existing(key);
	msg = msg_collect(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 99);
	msg = msg_collect(msq_id, 37, IPC_NOWAIT);
}

Test(msg, relay, .init = ipc_delete_test, .fini = ipc_delete_test) {
	key_t key = key_get(FTOK_FILE_PATH);
	int msq_id = msq_get_new(key);

	msq_id = msq_get_new(key);
	msg_send(msq_id, 6, (payld_t) {42, 0, 0});
	payld_t msg = msg_collect(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 42);
	msg_send(msq_id, 6, (payld_t) {37, 0, 0});
	msg_send(msq_id, 6, (payld_t) {99, 0, 0});
	msg = msg_collect_repeat(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 37);
	msq_id = msq_get_existing(key);
	msg = msg_collect(msq_id, 6, IPC_NOWAIT);
	cr_assert_eq(msg.p_a, 99);
	msg = msg_collect(msq_id, 37, IPC_NOWAIT);
}

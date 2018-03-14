/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lemipc
*/

#ifndef LEMIPC_H_
	#define LEMIPC_H_

	#include <sys/shm.h>
	#include <sys/ipc.h>
	#include <sys/sem.h>

#define FTOK_FILE_PATH "./.gitignore"
#define PROJ_ID 0x4242

#define IPC_AFLAGS (SHM_R | SHM_W)
#ifndef IPC_CFLAGS
	#define IPC_CFLAGS (IPC_CREAT | SHM_R | SHM_W)
#endif /* !IPC_CFLAGS */
#define BOARD_SIDE 20
#define BOARD_SIZE (BOARD_SIDE * BOARD_SIDE)
#ifndef NULL
	#define NULL (void *) 0
#endif /* !NULL */
#define RET_ERR -1
// #define RET_

key_t key_get(void);
void *shm_get_new(key_t key);
void *shm_get_existing(key_t key);

void shm_delete_from_scratch(void);
void shm_delete(key_t key);

int sem_suite_get(key_t key);

void sem_value_alter(int sem_id, int value);
void sem_value_add(int sem_id);
void sem_value_sub(int sem_id);
int sem_value_get(int semId);

void sem_delete(int sem_suite_id);

void ipc_delete(void);

#endif /* !LEMIPC_H_ */

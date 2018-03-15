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
	#include <sys/msg.h>

#define FTOK_FILE_PATH "./.gitignore"
#define PROJ_ID 0x4242

#define IPC_AFLAGS (SHM_R | SHM_W)
#define IPC_CFLAGS (IPC_CREAT | SHM_R | SHM_W)
#define BOARD_SIDE 20
#define BOARD_SIZE (BOARD_SIDE * BOARD_SIDE)
#ifndef NULL
	#define NULL (void *) 0
#endif /* !NULL */
#define RET_ERR -1
#define RET_OK 0
#define EXT_FAILURE 84
#define EXT_SUCCESS 0
#define SEM_NB 1

typedef struct	s_msg_data {
	int	d_b;
	int	d_a;
	int	d_c;
}		msg_data_t;

typedef struct		s_msg {
	long		m_channel;
	msg_data_t	m_data;
}			msg_t;

typedef struct	s_ipcs {
	char	*i_shmsg;
	key_t	i_key;
	int	i_sem_set;
	int	i_msq;
	int	i_gpid;
}		ipcs_t;

key_t	key_get(const char *path);
void	*shm_get_new(key_t key);
void	*shm_get_existing(key_t key);

void	shm_delete_from_scratch(void);
void	shm_delete(key_t key);

int	sem_suite_get(key_t key);

void	sem_value_alter(int sem_id, int value);
void	sem_value_unlock(int sem_id);
void	sem_value_lock(int sem_id);
int	sem_value_get(int semId);

void	sem_delete(int key);

void	ipc_delete(const char *path);
void	ipc_delete_test(void);

int	msq_get_new(key_t key);
int	msq_get_existing(key_t key);
void	msq_delete(key_t key);
msg_t	msg_collect(int msq_id, long channel);
void	msg_send(int msq_id, long channel, int code);

int	lem_start(const char *path, int team_nb);
int	lem_threads_bstrap(ipcs_t *ipcs);
int	lem_host(ipcs_t *ipcs);
int	lem_play(ipcs_t *ipcs);

#endif /* !LEMIPC_H_ */

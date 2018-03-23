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
	#include <stdbool.h>

#define FTOK_FILE_PATH "./.gitignore"
#define PROJ_ID 0x4242
#define POS_EMPTY '.'
#define MSG_CH_HOST 1
#define MSG_CH_BRD 2
#define MSG_CH_BASE 20

#define MSG_PLAYER_NEW 1
#define MSG_PLAYER_RDY 0
#define MSG_CYCLE 1
#define MSG_END 2
#define MSG_BUFF 3

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
#define SLEEP_TIME 500000
#define STALLED_CYCLES_MAX 10
#define IMPLEMENTED_STATEGIES 3

extern char *g_key_path;
extern int (*g_print_fcnt)(const char *format, ...);


typedef struct	s_ivector {
	int	v_x;
	int	v_y;
}		ivector_t;

typedef struct	s_payld {
	int	p_a;
	int	p_b;
	int	p_c;
}		payld_t;

typedef struct		s_msg {
	long		m_channel;
	payld_t		m_data;
}			msg_t;

typedef struct	s_ipcs {
	char	*i_shmsg;
	key_t	i_key;
	int	i_sem_set;
	int	i_msq;
	int	i_gpid;
	int	i_buff_time;
}		ipcs_t;

typedef struct	s_lem_opt {
	bool	ncurses;
	int	buff_time;
}		lem_opt_t;

key_t	key_get(const char *path);
void	*shm_get_new(key_t key);
void	*shm_get_existing(key_t key);

void	shm_print(ipcs_t *ipcs);
void	shm_delete_from_scratch(void);
void	shm_delete(key_t key);
void	shm_put(ipcs_t *ipcs, ivector_t where, char what);
bool	shm_put_try(ipcs_t *ipcs, ivector_t where, char what);
bool	shm_pos_is_free(ipcs_t *ipcs, ivector_t pos);
int	shm_pos_gpid_get(ipcs_t *ipcs, ivector_t pos);
size_t	shm_teams_count(char *shmsg);
bool	shm_is_stalled(ipcs_t *ipcs);
ivector_t shm_barycentre_find(ipcs_t *ipcs);
ivector_t shm_barycentre_find_target(ipcs_t *ipcs, int target);
ivector_t shm_foe_find(ipcs_t *ipcs, ivector_t player_pos);

int	sem_suite_get(key_t key);

void	sem_value_alter(int sem_id, int value);
void	sem_value_unlock(int sem_id);
void	sem_value_lock(int sem_id);
int	sem_value_get(int semId);

void	sem_delete(int key);

void	ipc_delete(const char *path);
void	ipc_delete_test(void);
void	ipc_delete_sigint(int signum);
int	ipc_init_new(ipcs_t *ipcs);
int	ipc_init_existing(ipcs_t *ipcs);

int	msq_get_new(key_t key);
int	msq_get_existing(key_t key);
void	msq_delete(key_t key);
payld_t	msg_collect(int msq_id, long channel, int flags);
payld_t msg_collect_repeat(int msq_id, long channel, int flags);
void	msg_send(int msq_id, long channel, payld_t payload);

int	lem_start(const char *path, int team_nb, int tempo);
int	lem_threads_bstrap(ipcs_t *ipcs);
int	lem_host(ipcs_t *ipcs);
int	lem_play(ipcs_t *ipcs);

size_t	host_wait_startup(ipcs_t *ipcs);
void	host_loop(ipcs_t *ipcs);

bool	player_move_towards(ipcs_t *ipcs, ivector_t *curr, ivector_t aim);
bool	player_move_to(ipcs_t *ipcs, ivector_t *curr, ivector_t new_pos);
bool	player_move_by(ipcs_t *ipcs, ivector_t *curr, ivector_t heading);
void	player_wait_startup(ipcs_t *ipcs);
ivector_t player_find_startpoint(ipcs_t *ipcs);
void	player_loop(ipcs_t *ipcs, ivector_t pos);
bool	player_is_killed(ipcs_t *ipcs, ivector_t pos);
bool	player_move_fromwards(ipcs_t *ipcs, ivector_t *curr, ivector_t aim);

void	player_strategy_1_run(ipcs_t *ipcs, ivector_t *pos);
void	player_strategy_2_run(ipcs_t *ipcs, ivector_t *pos);
void	player_strategy_3_run(ipcs_t *ipcs, ivector_t *pos);

void	display_basic(ipcs_t *ipcs);
void	display_ncurses(ipcs_t *ipcs);
void	display_ncurses_init(void);
void	display_select(ipcs_t *ipcs, bool mod);
#endif /* !LEMIPC_H_ */

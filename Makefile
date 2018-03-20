##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME		=	lemipc

MAIN		=	src/main.c

SRCS		=	src/shm/shm_get.c			\
			src/shm/shm_delete.c			\
			src/shm/shm_put.c			\
			src/shm/shm_pos.c			\
			src/shm/shm_print.c			\
			src/shm/shm_teams_count.c		\
			src/shm/shm_is_stalled.c		\
			src/shm/shm_barycentre_find.c		\
			src/key_get.c				\
			src/sem/sem_suite_get.c			\
			src/sem/sem_value_alter.c		\
			src/sem/sem_value_get.c			\
			src/sem/sem_delete.c			\
			src/ipc_delete.c			\
			src/ipc_init.c				\
			src/msg/msg_collect.c			\
			src/msg/msg_send.c			\
			src/msg/msq_get.c			\
			src/msg/msq_delete.c			\
			src/lem/lem_start.c			\
			src/lem/lem_host.c			\
			src/lem/lem_play.c			\
			src/lem/lem_threads_bstrap.c		\
			src/player/player_loop.c		\
			src/player/player_move.c		\
			src/player/player_wait.c		\
			src/player/player_find_startpoint.c	\
			src/player/player_is_killed.c		\
			src/player/player_ia_1.c		\
			src/player/player_ia_2.c		\
			src/host/host_loop.c			\
			src/host/host_wait.c			\
			src/host/host_terminate.c		\

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJS		=	$(SRCS:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test_sem.c	\
			tests/test_msg.c	\
			tests/test_shm.c	\
			tests/test_player.c	\
			tests/test_ipc.c

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

LDFLAGS		=	-L./ -lpthread

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: CFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: $(TEST) $(NAME)

tests_run: CC=gcc --coverage
tests_run: tests
	@./$(TEST) --jobs 1 || true
	@cd tests/ && find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@cd src/ && rm -f main.gcda main.gcno
#	 @bash ./tests/functional_tests.sh

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME) | tr " " "."
	@$(CC) $(OBJ_MAIN) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME) | tr " " "."

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(TEST) | tr " " "."
	@$(CC) $(OBJS_TEST) -o $(TEST) $(LDFLAGS) -lcriterion
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(TEST) | tr " " "."

clean: artifacts_clean
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."

artifacts_clean:
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" -o -name "*.html" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests tests_run clean cov_clean

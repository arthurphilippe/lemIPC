/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "lemipc.h"

int main(void)
{
	printf("hi\n");
	key_t key = key_get();
	char *addr = shm_get(key);
	// strcpy(addr, "salut");
	printf("%s\n", addr);
	shmdt(addr);
}
